#include "PageTools.hpp"



PageTools::PageTools(/* args */)
{
    makeListButton = ftxui::Button("Make list", []{});
    makeTodoButton  = ftxui::Button("Make Todo List", []{});

    Add(ftxui::Container::Vertical({
        makeListButton,
        makeTodoButton
    }));
}

PageTools::~PageTools()
{
}


ftxui::Element PageTools:: Render()
{
        return ftxui::vbox({
        makeListButton->Render(),
        makeTodoButton->Render()
    });
}