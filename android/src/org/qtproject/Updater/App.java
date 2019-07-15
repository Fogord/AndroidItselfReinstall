package org.qtproject.Updater;

import android.app.Application;

public class App extends Application {

    public static App INSTANCE;

    public void onCreate() {
        super.onCreate();
        INSTANCE = this;
    }
}
