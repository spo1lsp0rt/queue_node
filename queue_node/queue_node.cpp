// FIFO, она же — просто очередь, она же однонаправленный список, она же — линейный список.
//

#include <iostream>

struct Node {
    int x;
    Node* next;
};

class queue {
    Node *head, *tail;
    int q_size;

public:
    queue() : head(NULL), tail(NULL), q_size(0){};
    ~queue() {
        Node* temp = head; //Временный указатель на начало списка
        while (temp != NULL) { //Пока в списке что-то есть
            temp = head->next; //Резерв адреса на следующий элемент списка
            delete head; //Освобождение памяти от первой структуры как элемента списка
            head = temp; //Сдвиг начала на следующий адрес, который берем из резерва
        }
    }

    void push(int el) {
        Node* temp = new Node;
        temp->x = el;
        temp->next = NULL;
        if (head == NULL) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        q_size++;
    }

    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;
        q_size--;
    }

    int size() {
        return q_size;
    }

    int front() {
        return head->x;
    }

    int back() {
        return tail->x;
    }

    bool empty() {
        return q_size == 0;
    }
};

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    queue q;
    q.push(1);
    q.push(2);
    cout << "Добавили два элемента. Размер очереди: " << q.size() << endl;
    cout << "Первый элемент очереди: " << q.front() << endl;
    cout << "Последний элемент очереди: " << q.back() << endl;
    q.pop();
    cout << "Удалили элемент. Первый элемент очереди: " << q.front() << endl;
    cout << "Пуста ли очередь? Ответ: " << q.empty() << endl;
    q.pop();
    cout << "Удалили оставшийся элемент очереди. Пуста ли очередь? Ответ: " << q.empty() << endl;
}