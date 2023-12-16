#include <iostream>
#include <memory>

template <typename T, typename Alloc = std::allocator<T>>
class List{

private:

// Узел списка
    struct Node{
        T data;
        Node* next;
        Node* prev;
    };

    using Alloc_traits = std::allocator_traits<Alloc>;
    using Alloc_Node = typename Alloc_traits::rebind_alloc<Node>;
    using Alloc_Node_traits = std::allocator_traits<Alloc_Node>;
    Node* head;
    Node* tail;
    size_t size;
    Alloc_Node alloc;

public:
    class Iterator{

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node){
            current = node;
        }

        Iterator& operator++(){
            current = current->next;
            return *this;
        }

        T& operator*() const{
            return current->data;
        }

        bool operator==(const Iterator& other) const{
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const{
            return !(*this == other);
        }

    private:
        Node* current;
    };

    class ConstIterator{

    public:
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        ConstIterator(Node* node){
            current = node;
        }

        ConstIterator& operator++(){
            current = current->next;
            return *this;
        }

        reference operator*() const{
            return current->data;
        }

        bool operator==(const ConstIterator& other) const{
            return current == other.current;
        }

        bool operator!=(const ConstIterator& other) const{
            return !(*this == other);
        }

    private:
        Node* current;
    };
    
    List(): alloc(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~List(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            Alloc_Node_traits::destroy(alloc, temp);
            Alloc_Node_traits::deallocate(alloc, temp, 1);
        }
    }

    int get_size() const{
        return size;
    }

    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(nullptr);
    }

    ConstIterator cbegin() const{
        return ConstIterator(head);
    }

    ConstIterator cend() const{
        return ConstIterator(nullptr);
    }

    void push_back(const T& value){
        Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
        Alloc_Node_traits::construct(alloc, new_node, value);

        if (head == nullptr){
            head = tail = new_node;
        } 
        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++size;
    }
    
    void push_front(const T& value){
        Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
        Alloc_Node_traits::construct(alloc, new_node, value);

        if (head == nullptr){
            head = tail = new_node;
        } 
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        ++size;
    }

    void pop_back(){
        if (tail == nullptr){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr){
            tail->next = nullptr;
        } 
        else{
            head = nullptr;
        }
        Alloc_Node_traits::destroy(alloc, temp);
        Alloc_Node_traits::deallocate(alloc, temp, 1);
        size--;
    }

    void pop_front(){
        if (head == nullptr){
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        Alloc_Node_traits::destroy(alloc, temp);
        Alloc_Node_traits::deallocate(alloc, temp, 1);
        size--;
    }

    void insert(size_t index, const T& value){
        if(index > size){
            std::cout << "Невозможно вставить эллемент " << value << ", так как в списке нет индекса: " << index << "\n";
        }
        if(index == 0){
            push_front(value);
        }
        else if(index == size){
            push_back(value);
        }
        else{
            Node* current = head;
            for(size_t i = 0; i < index; i++){
                current = current->next;
            }

            Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
            Alloc_Node_traits::construct(alloc, new_node, value);

            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;

            size++;
        }
    }

    void erase(size_t index){
        if(index >= size){
            std::cout << "Нет данных с таким индексом." << "\n";
        }
        if(index == 0){
            pop_front();
        }
        else if(index == size - 1){
            pop_back();
        }
        else {
            Node* current = head;
            for(size_t i = 0; i < index; i++){
                current = current->next;
            }
            Node* delete_node = current;

            current->prev->next = current->next;
            current->next->prev = current->prev;
            
            Alloc_Node_traits::destroy(alloc, delete_node);
            Alloc_Node_traits::deallocate(alloc, delete_node, 1);
            
            size--;
        }
    }
};