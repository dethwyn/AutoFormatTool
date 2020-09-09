#ifndef STATE_H
#define STATE_H

#include <QString>
#include <QStringList>

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
    // Главное окно
    QString menuFileText;
    QString menuSettingText;
    QString menuExitText;
    QString buttonBrowseText;
    QString linePathText;
    QString labelPathText;
    QString buttonRefreshText;
    QStringList listFilesStringList;
    QString buttonFormatText;
    int progressBarValue;
    int progressBarType;
    // Окно настроек
    QString buttonBrowseUcText;
    QString linePathUcText;
    QString labelPathUcText;
    QString buttonBrowseCfgText;
    QString labelPathCfgText;
    QString linePathCfgText;
    QString buttonSaveText;
    QString buttonCloseText;

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
    // Геттеры главного окна
    QString getMenuFileText();
    QString getMenuSettingText();
    QString getMenuExitText();
    QString getButtonBrowseText();
    QString getLinePathText();
    QString getLabelPathText();
    QString getButtonRefreshText();
    QStringList getListFilesStringList();
    QString getButtonFormatText();
    int getProgressBarValue();
    int getProgressBarType();
    // Сеттеры главного окна
    void setMenuFileText(const QString &text);
    void setMenuSettingText(const QString &text);
    void setMenuExitText(const QString &text);
    void setButtonBrowseText(const QString &text);
    void setLinePathText(const QString &text);
    void setLabelPathText(const QString &text);
    void setButtonRefreshText(const QString &text);
    void setListFilesStringList(const QStringList &list);
    void addItemListFiles(const QString &item);
    void setButtonFormatText(const QString &text);
    void setProgressBarValue(int value);
    void setProgressBarType(int type);
    // Геттеры окна настроек

    // Сеттеры окна настроек
};

#endif // STATE_H