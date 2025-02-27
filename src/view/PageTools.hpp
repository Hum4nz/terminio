#ifndef __PAGE_NOTE_TOOL__
#define __PAGE_NOTE_TOOL__

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <memory>
#include <string>
#include <vector>



class PageTools : public ftxui::ComponentBase
{
private:
    ftxui::Component makeListButton;
    ftxui::Component makeTodoButton;
public:
    PageTools();
    ~PageTools();

    ftxui::Element Render() override;
};

#endif //__PAGE_NOTE_TOOL__
