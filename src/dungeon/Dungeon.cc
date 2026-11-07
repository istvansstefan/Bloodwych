#include "Dungeon.hh"

#include <stdexcept>

Dungeon::Dungeon(const std::vector<std::string>& map)
    : width_(map.empty() ? 0 : static_cast<int>(map[0].size())),
      height_(static_cast<int>(map.size()))
{
    if (width_ == 0 || height_ == 0)
        throw std::invalid_argument("Empty dungeon map");

    for (const auto& row : map)
    {
        if (static_cast<int>(row.size()) != width_)
            throw std::invalid_argument("Inconsistent dungeon map width");

        for (char cell : row)
        {
            switch (cell)
            {
                case '#':
                    tiles_.push_back({TileType::Wall});
                    break;

                case '.':
                    tiles_.push_back({TileType::Floor});
                    break;

                default:
                    throw std::invalid_argument("Unknown dungeon map character");
            }
        }
    }
}

int Dungeon::width() const
{
    return width_;
}

int Dungeon::height() const
{
    return height_;
}

const Tile& Dungeon::tileAt(int x, int y) const
{
    if (x < 0 || x >= width_ || y < 0 || y >= height_)
        throw std::out_of_range("Dungeon coordinates out of range");

    return tiles_[y * width_ + x];
}
