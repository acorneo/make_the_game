//
// Created by max on 6/21/25.
//

#ifndef LINE_HPP
#define LINE_HPP

namespace UI {
    class Line {
    public:
        int xStartPos{0};
        int yStartPos{0};
        int xEndPos{100};
        int yEndPos{100};
        int thickness{3};
        Color color{GetColor(0x000000FF)};
        int zIndex{0};
    };
}

#endif //LINE_HPP
