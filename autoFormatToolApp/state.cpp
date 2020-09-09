#include "state.h"

State *State::instance = nullptr; // инициализация инстанса
StateDestructor State::destructor; // объявление деструктора
/*!
 * \brief – дестркутор экземпляра State
 */
StateDestructor::~StateDestructor() {
    delete instance;
}
/*!
 * \brief – Функция переприсваивает указатель на экземпляр, хранящийся в классе деструктора
 * \param instancePointer – указатель на экземпляр State
 */
void StateDestructor::initialize(State *instancePointer) {
    instance = instancePointer;
}
/*!
 * \brief – Возвращает указатель на экземпляр State, если его нет - создает и передает его в класс деструктора
 * \return – указатель на экземпляр State
 */
State& State::getInstance() {
    if(!instance) {
        instance = new State();
        destructor.initialize(instance);
    }
    return *instance;
}
/*!
 * \brief – Пустой деструктор State (экземпляр автоматически удаляется классом StateDestructor)
 */
State::~State() {
}
/*!
 * \brief – Основной конструктор первоначальной инициализации состояния
 */
State::State() {
}
