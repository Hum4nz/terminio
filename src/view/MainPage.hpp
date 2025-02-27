
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include "NotesPage.hpp"

using namespace ftxui;

class MainPage
{
private:
    ScreenInteractive _screen;
    Component _contentTools;
    Component _menuTools;
    Component _menu;
    std::shared_ptr<NotesPage> _page;
    Component _content;
    Element _grid;
    Component _mainRenderer;
    Component _pageContainer; 

    Component addButton;

    std::vector<std::string> entries;

    int selected;

    void NewPageClick();

public:
    MainPage(/* args */);
    void Render();
    ~MainPage();
};

