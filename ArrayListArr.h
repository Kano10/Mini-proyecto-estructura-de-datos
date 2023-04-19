

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
	ArrayListArr* first;//Apuntará al último ArrayListArr
	ArrayListArr* end;//apuntará al primer ArrayListArr

public:
	ArrayListArr();
	~ArrayListArr();
	
};
