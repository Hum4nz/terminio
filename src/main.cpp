// #include <ncurses.h>
// #include <vector>
// #include <string>
// #include <iostream>
// #include <stdio.h>

// #ifdef OK
// #undef OK
// #endif

// #include <SQLiteCpp/SQLiteCpp.h>

// std::shared_ptr<SQLite::Database> db;

// class Menu {
// private:
//     std::vector<std::string> options;
//     int selected;

// public:
//     Menu(const std::vector<std::string>& items) : options(items), selected(0) {}

//     void display() {
//         clear();
//         mvprintw(0, 0, "Usa le frecce per navigare e Invio per selezionare:");
//         for (size_t i = 0; i < options.size(); ++i) {
//             if ((int)i == selected) {
//                 attron(A_REVERSE); // Evidenziare l'opzione selezionata
//                 mvprintw(2 + i, 2, options[i].c_str());
//                 attroff(A_REVERSE);
//             } else {
//                 mvprintw(2 + i, 2, options[i].c_str());
//             }
//         }
//         refresh();
//     }

//     void navigate(int key) {
//         switch (key) {
//             case KEY_UP:
//                 selected = (selected - 1 + options.size()) % options.size();
//                 break;
//             case KEY_DOWN:
//                 selected = (selected + 1) % options.size();
//                 break;
//         }
//     }

//     int getSelection() const { return selected; }
// };



// void initDB()
// {

//     db = std::make_shared<SQLite::Database>("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
//     db->exec("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, value TEXT)");
// }

// int main() {
//     // Inizializza ncurses
//     initscr();
//     cbreak();
//     noecho();
//     keypad(stdscr, TRUE);
//     curs_set(0);
//     initDB();

//     // Creare il menu
//     std::vector<std::string> items = {"Saluta", "Inserisci una nota", "mostra notenote", "Esci"};
//     Menu menu(items);

//     int input;
//     while (true) {
//         menu.display();
//         input = getch();
//         if (input == '\n') {
//             clear();
//             int selection = menu.getSelection();
//             if (selection == 0) {
//                 mvprintw(0, 0, "Ciao! Benvenuto nel programma.");
//             } else if (selection == 1) {
//                 char a[50];
//                 char query[300];
//                 mvprintw(0, 0, "Inserisci una nota: ");
//                 getnstr(a, 10);

//                 sprintf(query, "INSERT INTO test VALUES (NULL, \"%s\")", a);
//                 db->exec(query);

//             }
//             else if(selection == 2)
//             {
//                 SQLite::Statement   query(*db, "SELECT * FROM test");
//                 std::cout << "SELECT * FROM test :\n";
//                 int a = 0;
//                 while (query.executeStep())
//                 {
//                     std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
//                     mvprintw(a, 0, query.getColumn(1));
//                     a++;
//                 }
               
//             } else if (selection == 3) {
//                 mvprintw(0, 0, "Uscita dal programma.");
//                 break;
//             }
//             getch();
//         } else {
//             menu.navigate(input);
//         }
//     }

//     // Termina ncurses
//     endwin();
//     return 0;
// }



// #include <ftxui/component/component.hpp>
// #include <ftxui/component/screen_interactive.hpp>
// #include <ftxui/dom/elements.hpp>

#include "view/MainPage.hpp"

int main() {
    using namespace ftxui;

   std::unique_ptr<MainPage> mainPage = std::make_unique<MainPage>();
   mainPage->Render();

   
}


// using namespace ftxui;

// #include <ftxui/component/component.hpp>
// #include <ftxui/component/screen_interactive.hpp>
// #include <string>
// #include <vector>

// int main() {
//     using namespace ftxui;

//     // Lista dei checkbox
//     auto checkbox_list = Container::Vertical({});
//     std::vector<std::string> labels(10, "Checkbox ");
//     std::vector<std::shared_ptr<bool>> states(labels.size());

//     for (size_t i = 0; i < labels.size(); ++i) {
//         states[i] = std::make_shared<bool>(false);
//         auto checkbox = Checkbox((const std::string*) &(labels[i] += std::to_string(i)), states[i].get());
//         checkbox_list->Add(checkbox);
//     }

//     // Renderer con scrolling verticale
//     auto renderer = Renderer(checkbox_list, [&] {
//         return checkbox_list->Render() | vscroll_indicator | frame | border |
//                size(HEIGHT, LESS_THAN, 10);  // Limita l'altezza della lista
//     });

//     // Avvio dello schermo interattivo
//     auto screen = ScreenInteractive::TerminalOutput();
//     screen.Loop(renderer);

//     return 0;
// }

