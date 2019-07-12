package org.qtproject;

import android.app.Application;

public class App extends Application {

    public static App INSTANCE;

    public void onCreate() {
        super.onCreate();
        INSTANCE = this;
    }
}
