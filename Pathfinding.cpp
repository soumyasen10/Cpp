#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct Node {
    int x, y;
    double g, h; 
    Node* parent;

    Node(int x, int y, double g, double h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    double f() const { return g + h; }
};

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

double heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2); 
}

void a_star(const std::vector<std::vector<int>>& grid, int startX, int startY, int goalX, int goalY) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> open_list;
    std::vector<std::vector<bool>> closed_list(grid.size(), std::vector<bool>(grid[0].size(), false));

    open_list.push(new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY)));

    while (!open_list.empty()) {
        Node* current = open_list.top();
        open_list.pop();

        if (current->x == goalX && current->y == goalY) {
            std::cout << "Path found!\n";
            // Output path
            while (current) {
                std::cout << "(" << current->x << "," << current->y << ") ";
                current = current->parent;
            }
            std::cout << "\n";
            return;
        }

        closed_list[current->x][current->y] = true;

        std::vector<std::pair<int, int>> neighbors = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const auto& neighbor : neighbors) {
            int newX = current->x + neighbor.first;
            int newY = current->y + neighbor.second;

            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0 && !closed_list[newX][newY]) {
                double newG = current->g + 1;
                double newH = heuristic(newX, newY, goalX, goalY);
                open_list.push(new Node(newX, newY, newG, newH, current));
            }
        }
    }

    std::cout << "No path found.\n";
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    a_star(grid, 0, 0, 4, 4);

    return 0;
}
