#include "dungeon/Dungeon.hh"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{

int failures = 0;

void check(bool condition, const std::string& description)
{
    if (condition)
    {
        std::cout << "[PASS] " << description << '\n';
    }
    else
    {
        std::cerr << "[FAIL] " << description << '\n';
        ++failures;
    }
}

template <typename Exception, typename Function>
void checkThrows(Function function, const std::string& description)
{
    try
    {
        function();
        check(false, description);
    }
    catch (const Exception&)
    {
        check(true, description);
    }
    catch (...)
    {
        check(false, description + " (unexpected exception type)");
    }
}

} // namespace

int main()
{
    const std::vector<std::string> map = {
        "########",
        "#......#",
        "#..##..#",
        "#......#",
        "#...#..#",
        "#......#",
        "########"
    };

    Dungeon dungeon(map);

    // Dimensions
    check(dungeon.width() == 8, "Dungeon width is 8");
    check(dungeon.height() == 7, "Dungeon height is 7");

    // Tile access
    check(dungeon.tileAt(0, 0).type == TileType::Wall,
          "Top-left tile is a wall");

    check(dungeon.tileAt(1, 1).type == TileType::Floor,
          "Tile (1, 1) is a floor");

    check(dungeon.tileAt(3, 2).type == TileType::Wall,
          "Tile (3, 2) is a wall");

    check(dungeon.tileAt(7, 6).type == TileType::Wall,
          "Bottom-right tile is a wall");

    // Invalid maps
    checkThrows<std::invalid_argument>(
        [] { Dungeon emptyMap({}); },
        "Empty map is rejected");

    checkThrows<std::invalid_argument>(
        [] { Dungeon invalidMap({"####", "##"}); },
        "Inconsistent row widths are rejected");

    checkThrows<std::invalid_argument>(
        [] { Dungeon invalidMap({"##", "#X"}); },
        "Unknown map characters are rejected");

    // Invalid coordinates
    checkThrows<std::out_of_range>(
        [&] { dungeon.tileAt(-1, 0); },
        "Negative X coordinate is rejected");

    checkThrows<std::out_of_range>(
        [&] { dungeon.tileAt(8, 0); },
        "X coordinate beyond width is rejected");

    checkThrows<std::out_of_range>(
        [&] { dungeon.tileAt(0, 7); },
        "Y coordinate beyond height is rejected");

    std::cout << "\n";

    if (failures == 0)
    {
        std::cout << "All tests passed!\n";
        return 0;
    }

    std::cerr << failures << " test(s) failed.\n";
    return 1;
}
