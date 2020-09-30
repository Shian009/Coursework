package com.example.p3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    Button b;
    EditText e;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b=findViewById(R.id.button);
        e=findViewById(R.id.editText);
        b.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                Intent i= new Intent(MainActivity.this,Main2Activity.class);
                i.putExtra("Value",e.getText().toString());
                startActivity(i);
            }
        });
    }


}
