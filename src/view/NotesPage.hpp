#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

#include "NoteInput.hpp"
#include "PageTools.hpp"

using namespace ftxui;


class NotesPage : public ftxui::ComponentBase
{

private:
    std::string title_;
    std::string body_;
    ftxui::Component titleInput_;
    ftxui::Component bodyInput_;
    std::shared_ptr<NoteInput> noteInput;
    Component _pageNoteTools; 


public:
    NotesPage();
    ftxui::Element Render() override;

    ~NotesPage();
};