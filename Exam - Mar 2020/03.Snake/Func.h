#pragma once
#ifndef FUNC_H
#define FUNC_H

#include "Snake.h"
#include <algorithm>

namespace Func {
	StatusCode statusupdate(const Direction dir, std::deque<Point>& _snakeNodes, const std::vector<Point>& obstacles, std::vector<Point>& powerUps, Point& _currPos, const int fieldRows, const int fieldCols) {
		if (_currPos.col >= 0 && _currPos.row >= 0 && _currPos.row < fieldRows && _currPos.col < fieldCols) {
			std::vector<Point>::const_iterator it;
			it = find(obstacles.begin(), obstacles.end(), _currPos);
			if (it != obstacles.end())
				return StatusCode::SNAKE_DEAD;
			std::vector<Point>::iterator itr;
			itr = find(powerUps.begin(), powerUps.end(), _currPos);
			if (itr != powerUps.end()) {
				_snakeNodes.emplace_front(_currPos);
				itr = powerUps.erase(itr);
				return StatusCode::SNAKE_GROWING;
				}
			std::deque<Point>::iterator dit;
			dit = find(_snakeNodes.begin(), _snakeNodes.end(), _currPos);
			if (dit != _snakeNodes.end())
				return StatusCode::SNAKE_DEAD;
		}
		else
			return StatusCode::SNAKE_DEAD;

		if (_snakeNodes.size() == 1)
			_snakeNodes.front() = _currPos;
		else {
			_snakeNodes.pop_back();
			_snakeNodes.emplace_front(_currPos);
		}
		return StatusCode::SNAKE_MOVING;
	}
}

#endif // !FUNC_H