#ifndef __SQUARE_H
#define __SQUARE_H

class Square
{
public:
	Square() = default;
	Square(int row ,int col);
	~Square();
	void SetRow(int row);
	void SetCol(int col);

	int getRow() const;
	int getCol() const;


	bool operator==(const Square& other);

private:
	int m_row, m_col;
};

#endif // !__SQUARE_H