#include "NotesPage.hpp"
#include "PageTools.hpp"

NotesPage:: NotesPage() {
    titleInput_ = ftxui::Input(&title_, "Enter title");
    bodyInput_ = ftxui::Input(&body_, "Enter body");
    noteInput = std::make_shared<NoteInput>();
    _pageNoteTools = ftxui::Make<PageTools>();

auto inputContainer = ftxui::Container::Vertical({
    titleInput_,
    bodyInput_,
    noteInput
});

Add(ftxui::Container::Vertical({
    _pageNoteTools,
    inputContainer
}));

}

ftxui::Element NotesPage :: Render() 
{
       return vbox({
            // Visualizzazione del contenuto
            // Input sotto
            hbox({
                
            vbox({
                hbox(text(" Title: "), titleInput_->Render()),
                hbox(text(" Body:  "), bodyInput_->Render()),
                hbox(text(" Body:"), noteInput->Render())
            }) | flex,
            _pageNoteTools->Render() | align_right
            })
        });
}


NotesPage:: ~NotesPage(){

}
