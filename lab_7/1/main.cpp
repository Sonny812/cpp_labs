#include <iostream>

int main()
{
    // 1
    static int i = 5;
    int *pointerI = &i;
    int &refI = i;

    static float f = 5.1;
    float *pointerF = &f;
    float &refF = f;

    static char c = 'e';
    char *pointerC = &c;
    char &refC = c;

    void *pointerV = &c;

    i = *pointerI + refF;
    refF = static_cast<float>(*pointerF * refF);
    *(char *)pointerV = 'a';

    // 2
    std::cout << "Address of variable i: " << pointerI << std::endl; // получение адреса переменной
    std::cout << "Address of pointer: " << &pointerI << std::endl;   // получение адреса указателя
    std::cout << "Value on pointer: " << *pointerI << std::endl;     // получение значение по указателю

    if (pointerV == pointerC)
    { // сравнение указателей
        std::cout << "Void pointer and and char pointer are equal" << std::endl;
    }

    std::cout << "Type cast from char to int: " << *(static_cast<int *>(pointerV)) << std::endl;

    // 3
    const int constI = 1;
    int ii = 2;
    // int *const constPointer = &constI; действие невозмжно: нельзя инициализировать указатель не на константу адресом константы
    int *const constPointer = &ii; // константный указатель должен быть проинициализирован
    int const &constRef = ii;      // константная ссылка
    int const *pointerOnConst;     // неконстантный указатель на константу может быть не инициализирован при объявлении
    pointerOnConst = &constI;

    // 4
    void **pointerToPointer = (void **)&pointerI; // указатель на указатель
    // ссылки на ссылку не существует
    int &refRefI = refI; // "ссылка на ссылку" (все еще ссылка на int)

    // 5
    int intVariable = 1;
    const int constantInt = 2;
    int const *const constPointerToConstInt = &constantInt; // константный указатель на константу. Необходимо инициализировать при объявлении
    int const *pointerToConstInt;                           // указатель на константу. Может быть не инициализирован.
    pointerToConstInt = &intVariable;                       // может указывать на константу и не константу
    int *const intConstPointer = &intVariable;              // константный указатель. Должен быть проиницилизирован. Не может указывать на константу

    // ссылка всегда константны и должны быть инициализированы при объявлении
    // int& refToNotConst = constantInt; ссылка на не константу не может указывать на константу.
    const int &constantIntRef = constantInt;
}