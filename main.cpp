
#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int row;
    int column;
    int value;
    Node *next;
    Node(int row,int column,int value,Node* next )
    {
        this->row=row;
        this->column=column;
        this->value=value;
        this->next=next;
    }

};

Node* sparseMatrixLinkedListImplementation(vector<vector<int>> sparseMatrix,int rows,int columns, int row, int column)
{
    if(column>=columns)
    {
        return sparseMatrixLinkedListImplementation(sparseMatrix,rows,columns,row+1,0);
    }
    if(row>=rows)
    {
        return NULL;
    }
    if(sparseMatrix[row][column]==0)
    {
        return sparseMatrixLinkedListImplementation(sparseMatrix,rows,columns,row,column+1);
    }
    Node* NewNode=new Node(row,column,sparseMatrix[row][column], sparseMatrixLinkedListImplementation(sparseMatrix,rows,columns,row,column+1));
     
    return NewNode;
}

int main()
{
    int rows,columns;
    cout << " enter the numbers of rows:" << endl;
    cin >> rows;
	 cout << " enter the numbers of columns:" << endl;
    cin >> columns;
	vector<vector<int>> sparseMatrix(rows, vector<int>(columns));
	
    for (int i = 0; i < rows; i++)
    {
		for (int j = 0; j < columns; j++)
        {
            cout << " enter the value at "<< i << "th row and " << j<< "th column:" << endl; 
            cin >> sparseMatrix[i][j];
        }
    }


    Node* finalNode=sparseMatrixLinkedListImplementation(sparseMatrix,rows,columns,0,0);
    cout << " the LinkedList implementation of the given sparse matrix is :" << endl;
    
    while(finalNode!=NULL)
    {
        cout << "row : " << finalNode->row<<", column : "<<finalNode->column<<", value : "<<finalNode->value;
        cout <<"\n";
        finalNode=finalNode->next;
    } 
	return 0;
}


