#include "Square.h"

Square::Square(int row, int col)
{
	SetRow(row);
	SetCol(col);
}

Square::~Square()
{
}

void Square::SetRow(int row)
{
	m_row = row;
}

void Square::SetCol(int col)
{
	m_col = col;
}

int Square::getRow() const
{
	return m_row;
}

int Square::getCol() const
{
	return m_col;
}

bool Square::operator==(const Square & other) //defines square's condition of equality operator
{
	return (m_col == other.getCol() && m_row == other.getRow());

}
