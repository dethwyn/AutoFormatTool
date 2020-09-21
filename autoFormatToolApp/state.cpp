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
    delete listFileInfos;
}
/*!
 * \brief – Основной конструктор первоначальной инициализации состояния
 */

int State::getWndPosX() const
{
    return wndPosX;
}

void State::setWndPosX(int value)
{
    wndPosX = value;
}

int State::getWndPosY() const
{
    return wndPosY;
}

void State::setWndPosY(int value)
{
    wndPosY = value;
}

int State::getWndWidth() const
{
    return wndWidth;
}

void State::setWndWidth(int value)
{
    wndWidth = value;
}

int State::getWndHeight() const
{
    return wndHeight;
}

void State::setWndHeight(int value)
{
    wndHeight = value;
}

State::State() {
    // Главное окно
    menuFileText = "Файл";
    menuSettingText = "Настройки";
    menuExitText = "Выход";
    buttonBrowseText = "Обзор";
    linePathText = "";
    labelPathText = "Путь до исходников";
    buttonRefreshText = "Обновить";
    listFileInfos = new QFileInfoList();
    listFileInfos->clear();
    buttonFormatText = "Форматировать";
    progressBarValue = 0;
    progressBarType = 0;
    progressBarMax = 1000;
    wndPosX = 100;
    wndPosY = 100;
    wndWidth = 510;
    wndHeight = 300;
    // Окно настроек
    buttonBrowseUcText = "Обзор";
    linePathUcText = "";
    labelPathUcText = "Путь до Uncrustify";
    buttonBrowseCfgText = "Обзор";
    labelPathCfgText = "Путь до конфига";
    linePathCfgText = "";
    buttonSaveText = "Сохранить";
    buttonCloseText = "Закрыть";
    // Разное
    secretCode = "";
}
