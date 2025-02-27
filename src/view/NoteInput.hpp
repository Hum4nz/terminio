#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <memory>
#include <string>
#include <vector>


using namespace ftxui;
class NoteInput : public ftxui::ComponentBase {
    bool is_checkbox_;              // True: il componente è un checkbox
    std::string checkbox_label_;    // Etichetta del checkbox
    bool checkbox_state_;           // Stato del checkbox
    std::string text_;              // Testo dell'input di testo

    ftxui::Component checkbox_;     // Componente checkbox
    ftxui::Component text_input_;   // Componente input di testo

public:
    NoteInput()
        : is_checkbox_(false), 
          checkbox_label_("Checkbox"), 
          checkbox_state_(false), 
          text_("Enter text") {
        // Crea i due componenti
        checkbox_ = ftxui::Checkbox(&checkbox_label_, &checkbox_state_);
        text_input_ = ftxui::Input(&text_, "Enter text");
    }

    // Metodo per impostare il componente come checkbox
    void SetAsCheckbox(const std::string& label) {
        is_checkbox_ = true;
        checkbox_label_ = label;
    }

    // Metodo per impostare il componente come input di testo
    void SetAsTextInput() {
        is_checkbox_ = false;
    }

    // Renderizzazione dinamica
    ftxui::Element Render() override {
        if (is_checkbox_) {
            return ftxui::vbox({
                checkbox_->Render(),
            });
        } else {
            return ftxui::vbox({
                text_input_->Render(),
            });
        }
    }

    // Getters per ottenere il valore attuale
    const std::string& GetText() const { return text_; }
    bool GetCheckboxState() const { return checkbox_state_; }
};
