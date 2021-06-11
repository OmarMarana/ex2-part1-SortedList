 #ifndef SORTEDLIST_H_ //SortedList.h
 #define SORTEDLIST_H_
#include <iostream>



namespace mtm
{
    template<class T>
    class SortedList
    {
        public:
            class const_iterator;

            SortedList(); //constructor
            ~SortedList(); //destructor
            SortedList(const SortedList&); //copy constructor

            SortedList& operator=(const SortedList& other); // list1 = list2;
            void insert(T data);
            void remove(const_iterator element);
            int length() const;
            
            // typename Predicate 

            template<class Predicate>
            SortedList filter(Predicate predicate) const; 

            template<class Apply_func>
            SortedList apply(Apply_func func) const;


            /*
            apply and filter methodes to be done...
            */

            const_iterator begin() const;
            const_iterator end() const;

            void print() const;

        private:
            class Node;
            Node* head;
            void clearNodes();
    };

    template <class T>
    class SortedList<T>::const_iterator
    {
        friend class SortedList;

        const SortedList* list;
        int index;

        const_iterator(const SortedList* list, int index);

        public:
            ~const_iterator() = default;
            const_iterator(const const_iterator& iterator) = default;
            const_iterator& operator=(const const_iterator&) = default;

            const_iterator& operator++(); // Usage: ++ it1 , if out of bound, throw std::out_of_range
            bool operator==(const const_iterator& other) const;
            const T operator*() const;
    };

    template<class T>
    class SortedList<T>::Node
    {
        public:
            Node(const T data);
            Node(const Node& node);
            ~Node();
        
            const T data;
            Node* next;
    };

    /* ********************* */
    /* *LIST IMPLEMENTATION* */
    /* ********************* */
    

    /* Constructor */
    template<class T>
    SortedList<T>::SortedList() : head(nullptr)
    { }

    /* Destructor */
    template<class T>
    SortedList<T>::~SortedList()
    {
        clearNodes();
    }

    /* Copy Constructor */
    template<class T>
    SortedList<T>::SortedList(const SortedList<T>& other) : head(nullptr)
    {
        Node* ptr = other.head;

        while(ptr != nullptr)
        {
            insert(ptr->data);
            ptr = ptr->next;
        }
    }
    
    /* operator = */
    template<class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList<T>& other)
    {
        if(this == &other)
        {
            return *this;
        }
        this->clearNodes();

        for (const_iterator it = other.begin(); ! (it == other.end()); ++it)
        {
            this->insert(*it);
        }
        return *this;
    }

    /* Insert */
    template<class T>
    void SortedList<T>::insert(T data)
    {
        Node* new_node = new Node(data);
        if(head == nullptr)
        {
            head = new_node;
            return;
        }

        Node* prev;
        Node* current = head;

        if(data < head->data)
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        if(length() == 1)
        {
            head->next = new_node;
            return;
        }

        prev = head;
        current = head->next;

        while(current != nullptr)
        {
            if(data < current->data)
            {
                prev->next = new_node;
                new_node->next = current;
                return;
            }
            prev = prev->next;
            current = current->next;
        }

        prev->next = new_node;
    }

    template<class T>
    void SortedList<T>::remove(const_iterator element)
    {
        if(element.index >= length())
        {
            return;
        }

        if(length() == 1)
        {
            delete head;
            head = nullptr;
            return;
        }

        if(element.index == 0)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        
        Node* prev = head;
        Node* current =  head;

        for(int i = 0; i < element.index ; i++)
        {
            if(i == element.index - 1)
            {
                prev = current;
            }
            current = current->next;
        }

        Node* next =  current->next;
        delete current;
        prev->next = next;
    }


    /* Length */
    template<class T>
    int SortedList<T>::length() const
    {
        Node* ptr = head;
        int count = 0;

        while(ptr != nullptr)
        {
            ptr = ptr->next;
            count++;
        }

        return count;
    }
    
    
    template<class T>
    template<class Predicate>
    SortedList<T> SortedList<T>::filter(Predicate predicate) const
    {
        SortedList<T> filtered_list;

        for(typename SortedList<T>::const_iterator it = begin(); ! (it == end()); ++it)
        {
            if(predicate (*it))
            {
                filtered_list.insert(*it);
            }
        }

        return filtered_list;
        
    }

    template<class T>
    template<class Apply_func>
    SortedList<T> SortedList<T>::apply(Apply_func func) const
    {
        SortedList<T> result;

        for(typename SortedList<T>::const_iterator it = begin(); ! (it == end()); ++it)
        {
            T data = func(*it);
            result.insert(data);
        }

        return result;
    }


    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const
    {
        return const_iterator(this, 0);
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const
    {
        return const_iterator(this, this->length());
    }

    /* delete all the nodes in the list. */
    template<class T>
    void SortedList<T>::clearNodes()
    {
        Node* ptr = head;
        
        while(ptr != nullptr)
        {
            Node* next = ptr->next;

            delete ptr; 

            ptr = next;
        }
        head = nullptr;
    }

    /* DEBUG ONLY FUNCTIONS*/
    template<class T>
    void SortedList<T>::print() const
    {
        Node* ptr = head;
        for (int i = 0; i < this->length(); i++)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "END(nullptr)" << std::endl; 
    }

    /* ********************* */
    /* *NODE IMPLEMENTATION* */
    /* ********************* */

    /* NODE constructor */
    template<class T>
    SortedList<T>::Node::Node(const T data) : data(data), next(nullptr)
    {

    }

    /* copy constructor */
    template<class T>
    SortedList<T>::Node::Node(const Node& node) : data(node.data), next(node.next)
    {

    }

    /* Destructor */
    template<class T>
    SortedList<T>::Node::~Node()
    {
        //auto-call the destructor of data... ( T )
    }

    /* ************************* */
    /* *ITERATOR IMPLEMENTATION* */
    /* ************************* */
    
    /*constructor*/
    template<class T>
    SortedList<T>::const_iterator::const_iterator(const SortedList<T>* list, int index) : list(list), index(index)
    { }

    /*operator ++*/
    template<class T>
    typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++()
    {
        index++;
        // if(index >= list->length())
        // {
        //     throw std::out_of_range();
        // }
        return *this;
    }
    
    template<class T>
    bool SortedList<T>::const_iterator::operator==(const const_iterator& other) const
    {
        return index == other.index;
    }

    template<class T>
    const T SortedList<T>::const_iterator::operator*() const
    {
        
        Node* current =  list->head;
        for(int i = 0; i < index ; i++)
        {
            current = current->next;
        }
        return current->data; 
    }

}
#endif