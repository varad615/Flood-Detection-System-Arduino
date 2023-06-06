package com.ioe.flood;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;

import android.annotation.SuppressLint;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Toolbar;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.Map;
import java.util.Objects;

public class MainActivity extends AppCompatActivity {

    FirebaseDatabase firebaseDatabase;
    DatabaseReference databaseReference;
    private TextView water, temp;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FirebaseDatabase mData = FirebaseDatabase.getInstance();
        DatabaseReference mRef = mData.getReference("sensor");
        LinearLayout li = findViewById(R.id.appbackground);
        water = findViewById(R.id.waterlevel);
        temp = findViewById(R.id.templevel);





        mRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if (snapshot.exists()) {
                    Map map = (Map) snapshot.getValue();
                    assert map != null;
                    String waterlevel = Objects.requireNonNull(map.get("water")).toString();
                    String temperaturelevel = Objects.requireNonNull(map.get("temp")).toString();
                    double formatwater = Double.parseDouble(waterlevel);
                    double fromattemp = Double.parseDouble(temperaturelevel);
                    if (formatwater >= 9.0d) {
                        li.setBackgroundColor(Color.parseColor("#2DD93E"));
                    } else if (formatwater < 9.0d && formatwater >= 6.0d) {
                        li.setBackgroundColor(Color.parseColor("#0D99FF"));
                    } else {
                        li.setBackgroundColor(Color.parseColor("#FF3A3A"));
                    }
                    water.setText(waterlevel);
                    temp.setText(temperaturelevel);


                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }

    private void Clickme(){
        NotificationCompat.Builder builder =
                (NotificationCompat.Builder) new NotificationCompat.Builder(MainActivity.this)
                        .setSmallIcon(R.drawable.logo)
                        .setContentTitle("welcome")
                        .setContentText("hello");
        NotificationManager notificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        notificationManager.notify(0,builder.build());
    }
}