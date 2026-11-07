#pragma once

#include <vector>
#include <string>

enum class TileType
{
    Wall,
    Floor
};

struct Tile
{
    TileType type;
};

class Dungeon
{
public:
	explicit Dungeon(const std::vector<std::string>& map);

    int width() const;
    int height() const;

    const Tile& tileAt(int x, int y) const;

private:
    int width_;
    int height_;
    std::vector<Tile> tiles_;
};
