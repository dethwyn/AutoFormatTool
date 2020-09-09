#ifndef STATE_H
#define STATE_H

class State; // Опережающее объявление класса State для использования в StateDestructor

// Класс StateDestructor вспомогательный, для автоматического удаления State
class StateDestructor {
private:
    State *instance;
public:
    // ---Деструктор для удаления экземпляра State
    ~StateDestructor();
    // ---Метод первоначальной инициализации
    void initialize(State *instancePointer);
};

class State {
private:
    static State *instance; // Указатель на экземпляр состояния
    static StateDestructor destructor; // Экземпляр десруктора
protected:
    // ---Конструктор первой инициализации
    State();
    // ---Постоянная ссылка на экземпляр
    State(const State&);
    // ---Перегрузка оператора =, выполняет апкаст до указателя на экземпляр State
    State& operator = (State&);
    // ---Дестркутор State
    ~State();
    friend class StateDestructor; // для возможности уничтожения экземпляра State

public:
    static State& getInstance();
};

#endif // STATE_H
