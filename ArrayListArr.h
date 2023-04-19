

class ArrayListArr
{
private:
	struct ArrayListArr{
		int enUso;
		int array[tamaño];
		ArrayListArr* next;
		ArrayListArr(ArrayListArr* next = nullptr){
			this.next = next;
		}
	};

public:
	ArrayListArr();
	~ArrayListArr();
	
};
