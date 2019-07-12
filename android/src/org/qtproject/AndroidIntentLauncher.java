package org.qtproject;

import org.qtproject.qt5.android.QtNative;

import android.os.Environment;
import android.os.Build;
import android.util.Log;
import android.net.Uri;
import android.content.Intent;
import android.content.ContentValues;
import android.content.Context;
import android.content.pm.PackageInfo;

import androidx.core.content.FileProvider;
import androidx.fragment.app.Fragment;

import java.lang.String;
import java.io.File;



public class AndroidIntentLauncher{
    // this method will be called from C/C++
    private static final String DOWNLOADS_DIR = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).getPath();;
    private static final String FILE_NAME     = "Update.apk";
    private static final String FILE_TYPE     = "application/vnd.android.package-archive";

//    public static int fibonacci(int n) {
//        if (n < 2)
//            return n;
//        return fibonacci(n-1) + fibonacci(n-2);
//    }

    public static String  startWork() {
        try {
            if (QtNative.activity() == null) {
                return "Activity is not active";
            }

            Uri fileUri;
            if (Build.VERSION.SDK_INT >= 24) {
                fileUri = FileProvider.getUriForFile(
                          App.INSTANCE,
                          "org.qtproject",
                          new File(DOWNLOADS_DIR, FILE_NAME));
                 Intent intent = new Intent(Intent.ACTION_INSTALL_PACKAGE);
                 intent.setData(fileUri);
                 intent.setFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                 QtNative.activity().startActivity(intent);
            } else {
                fileUri = Uri.fromFile(new File(DOWNLOADS_DIR, FILE_NAME));
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setDataAndType(fileUri, FILE_TYPE);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                QtNative.activity().startActivity(intent);
            }
        } catch (android.content.ActivityNotFoundException anfe) {
            return "Something whent wrong (exceptions)";
        }

        return "";
    }
}
