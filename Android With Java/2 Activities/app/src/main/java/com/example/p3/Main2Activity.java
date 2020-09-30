package com.example.p3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Main2Activity extends AppCompatActivity {


    Button b;
    EditText e;
    TextView t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        t= findViewById(R.id.t1);
        t.setText(getIntent().getStringExtra("Value"));
    }
    public void callFA(View view){
        Intent i=new Intent(getApplicationContext(),MainActivity.class);
        startActivity(i);
    }
}