#include "Snake.h"
#include "Func.h"

using namespace Func;

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos): _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos)
{
	_snakeNodes.push_front(_currPos);
}

Snake::~Snake()
{
}

StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps)
{

	switch (dir)
	{
	case Direction::UP: {
		_currPos.row--;
		return statusupdate(dir, _snakeNodes, obstacles, powerUps, _currPos, _FIELD_ROWS, _FIELD_COLS); }
	case Direction::DOWN: {
		_currPos.row++;
		return statusupdate(dir, _snakeNodes, obstacles, powerUps, _currPos, _FIELD_ROWS, _FIELD_COLS); }
	case Direction::LEFT: {
		_currPos.col--;
		return statusupdate(dir, _snakeNodes, obstacles, powerUps, _currPos, _FIELD_ROWS, _FIELD_COLS); }
	case Direction::RIGHT: {
		_currPos.col++;
		return statusupdate(dir, _snakeNodes, obstacles, powerUps, _currPos, _FIELD_ROWS, _FIELD_COLS); }
	default: {
		return StatusCode::STATUS_UNKNOWN; }
	}


}

std::deque<Point>& Snake::getSnakeNodes()
{
	return _snakeNodes;
}
