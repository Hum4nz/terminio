#include "MainPage.hpp"

#include <iostream>
#include <stdio.h>


MainPage::MainPage() : _screen(ScreenInteractive::TerminalOutput()), entries(0), selected (0){

    _menu = Menu(&entries, &selected);

    _menuTools = Container::Vertical({});
    

    _pageContainer = Container::Vertical({});
    _page = std::make_shared<NotesPage>();
    _pageContainer->Add(_page);

    addButton = Button("New Note", [this] { NewPageClick(); });

    _menu |= CatchEvent([this](Event event) {
        if (event == Event::Return) {
            // L'utente ha premuto Enter sulla selezione corrente
            entries.insert(entries.begin(), "return");
            //std::cout << "Selezionato: " << entries[selected] << std::endl;
            return false;
        }
        if (event == Event::ArrowUp || event == Event::ArrowDown) {
            _pageContainer->DetachAllChildren(); // Rimuovi il vecchio contenuto
            _page = std::make_shared<NotesPage>();
            _pageContainer->Add(_page); // Aggiungi il nuovo contenuto
            _screen.PostEvent(Event::Custom); // Forza l'aggiornamento dello schermo
            return false; // Indica che l'evento è stato gestito
        }


        return false;
    });
    
    _menuTools->Add(addButton);

    auto layout = Container::Horizontal({
        Container::Vertical({
            _menuTools,
            _menu
        }),
        _pageContainer
    });

    // Crea il renderer per il layout
    _mainRenderer = Renderer(layout, [&] {
        return hbox({
            vbox({
                window(text("Tools"), _menuTools->Render()) | size(WIDTH, EQUAL, 20),
                window(text("Notes"), _menu->Render()) | size(WIDTH, EQUAL, 20)
            }),
            window(text("Note"), _page->Render()) | flex
        });
    });
}

void MainPage::Render() {
    _screen.Loop(_mainRenderer);
}


void MainPage:: NewPageClick()
{
    entries.insert(entries.begin(), "AAAAA");
}


MainPage::~MainPage()
{
}
