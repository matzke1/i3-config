// compile as: g++ spacer.C -o spacer $(pkg-config gtkmm-3.0 --cflags --libs)

#include <gtkmm.h>

static bool
maybe_quit(GdkEventKey *e) {
    if (e->keyval == GDK_KEY_q)
        exit(0);
    return true;
}


int
main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.spizella.spacer", Gio::ApplicationFlags::APPLICATION_NON_UNIQUE);
    Gtk::Window window;
    window.add_events(Gdk::KEY_PRESS_MASK | Gdk::KEY_RELEASE_MASK);
    window.signal_key_press_event().connect(sigc::ptr_fun(&maybe_quit));
    return app->run(window);
}
