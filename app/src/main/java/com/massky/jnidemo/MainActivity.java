package com.massky.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
       int c  =  add(1,2);

        try {
//            Test();
        } catch (Exception e) {
            Log.e("MainActivity", "onCreate: " + e);
        }

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    private native void Test() throws IllegalArgumentException;
    private native int add(int a , int b);

    private void callNullPointerException() throws NullPointerException {
        throw new NullPointerException("MainActivity NullPointerException");
    }

}
