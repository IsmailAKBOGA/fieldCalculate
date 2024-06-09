

/*This code is a console application that calculates the time
required to plow a rectangular field using the tractor and equipment
selected by the user, based on the maximum speed of the selected tractor
and the width of the equipment.This code is a console application that calculates
the time required to plow a rectangular field using the tractor and equipment selected
by the user, based on the maximum speed of the selected tractor and the width of the equipment.
note:In this code, inheritance could have been used, but I chose not to use it as this is the first version of the code.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Info {
public:

    int tractor_no = 0;
    int equipments_no = 0;
    float* e_width = nullptr;
    float* turn_time = nullptr;
    float* max_speed = nullptr;
};

class Tractors_no {
public:
    int Case_200 = 1;
    int Case_300 = 2;
    int Case_400 = 3;
    int Case_420 = 4;

    float speed_1 = 30;   // km/h
    float speed_2 = 35;
    float speed_3 = 40;
    float speed_4 = 45;
};

class Equipments_no {
public:
    int harrows_no = 1;
    int hoes_no = 2;
    int discs_no = 3;
    int Rculvitors_no = 4;
    int plow_no = 5;
};

class Equipments_width {
public:
    float harrows_w = 2;   // m
    float hoes_w = 3;
    float discs_w = 4;
    float Rculvitors_w = 5;
    float plow_w = 6;
};

class Field {
public:
    float* width = nullptr;
    float* length = nullptr;
};

void equipments_info(Field& f); //
void tractor_info(Info& t, Equipments_width& w);
void choose_equipment(Equipments_width& w, Info& t, Tractors_no& n);
void calculate(Info& t, Field& f);

int main() {
    Info t;
    Field f;
    Equipments_width w;
    Tractors_no n;

    t.e_width = new float;
    t.max_speed = new float;
    t.turn_time = new float;

    f.length = new float;
    f.width = new float;

    equipments_info(f);
    tractor_info(t, w);
    choose_equipment(w, t, n);
    calculate(t, f);

    delete t.turn_time;
    delete t.e_width;
    delete t.max_speed;
    delete f.length;
    delete f.width;

    return 0;
}

void equipments_info(Field& f) {
    cout << "                Field Info          " << endl;
    cout << ">--------------------------------------------------<" << endl;
    cout << "\nPlease input length of field (km): ";
    cin >> *(f.length);
    cout << "\nPlease input width of field (km): ";
    cin >> *(f.width);
    cout << "\n>--------------------------------------------------<\n" << endl;
}

void tractor_info(Info& t, Equipments_width& w) {
    cout << "          Tractor and equipment info\n" << endl;
    cout << "<-------------------------------------------------->\n" << endl;
    cout << "          Tractor Info      " << endl;
    cout << "<-------------------------------------------------->" << endl;
    cout << "!Attention: You can only enter it correctly 3 times." << endl;
    cout << "<-------------------------------------------------->\n" << endl;
    cout << "1. Case 200\n2. Case 300\n3. Case 400\n4. Case 420\n" << endl;
    cout << "Please choose a tractor: ";
    cin >> t.tractor_no;

    int i = 0;
    while (i < 3 && (t.tractor_no > 4 || t.tractor_no < 1)) {
        cout << "\nPlease input a number between 1 and 4!" << endl;
        cin >> t.tractor_no;

        if (i == 2 && (t.tractor_no > 4 || t.tractor_no < 1)) {
            cout << "!!!You entered it incorrectly 3 times!!!" << endl;
            exit(0);
        }
        i++;
    }

    cout << "          Equipment Info       " << endl;
    cout << "<-------------------------------------------------->" << endl;
    cout << "!Attention: You can only enter it correctly 3 times." << endl;
    cout << "<-------------------------------------------------->\n" << endl;
    cout << "1. Harrows\n2. Hoes\n3. Discs\n4. Rculvitor\n5. Plows\n" << endl;
    cout << "Please choose an equipment: ";
    cin >> t.equipments_no;
    cout << "\n>--------------------------------------------------<\n" << endl;
    int j = 0;
    while (j < 3 && (t.equipments_no > 5 || t.equipments_no < 1)) {
        cout << "Please input a number between 1 and 5!" << endl;
        cin >> t.equipments_no;

        if (j == 2 && (t.equipments_no > 5 || t.equipments_no < 1)) {
            cout << "!!!You entered it incorrectly 3 times.!!!" << endl;
            exit(0);
        }
        j++;
    }
}

void choose_equipment(Equipments_width& w, Info& t, Tractors_no& n) {
    switch (t.tractor_no) {
    case 1: { (*t.max_speed) = n.speed_1; } break;
    case 2: { (*t.max_speed) = n.speed_2; } break;
    case 3: { (*t.max_speed) = n.speed_3; } break;
    case 4: { (*t.max_speed) = n.speed_4; } break;
    }

    switch (t.equipments_no) {
    case 1: { (*t.e_width) = w.harrows_w; } break;
    case 2: { (*t.e_width) = w.hoes_w; } break;
    case 3: { (*t.e_width) = w.discs_w; } break;
    case 4: { (*t.e_width) = w.Rculvitors_w; } break;
    case 5: { (*t.e_width) = w.plow_w; } break;
    }
}

void calculate(Info& t, Field& f) {
    float field_area = 0, turns = 0;
    float len, fwid, ewid, speed, time;

    len = (*f.length);
    fwid = (*f.width);
    ewid = (*t.e_width);
    speed = (*t.max_speed);

    field_area = len * (fwid * 1000);

    turns = ((fwid * 1000) / ewid) - 1;
    int integer_turns = static_cast<int>(turns);

    if (integer_turns < turns) {
        integer_turns = integer_turns + 1;
    }
    else {
        integer_turns = turns;
    }

    time = (len / speed) * (integer_turns + 1);
    float float_time = time;
    float min = 0;
    int integer_time = static_cast<int>(time);

    if (float_time > integer_time) {
        min = float_time - integer_time;
        time = time - min;
    }

    int temp_time, month = 0, week = 0, day = 0, hour = 0, minute = 0;
    minute = min * 60;
    temp_time = time;

    cout << "       Calculated               " << endl;
    cout << "<-------------------------------------------------->" << endl;
    cout << "Vehicle speed: " << speed << " km/h" << endl;
    cout << "Equipments wide: " << ewid << " meter(s)" << endl;
    cout << fixed << setprecision(0) << "Area: " << field_area << " acres" << endl;
    cout << "Number of turns: " << integer_turns << endl;

    if (temp_time >= 24) {
        hour = (temp_time % 24);
        day = temp_time / 24;
        if (day >= 7) {
            week = day / 7;
            day = day % 7;

            if (week >= 4) {
                month = week / 4;
                week = week % 4;

                cout << "Net time: " << month << " month(s), " << week << " week(s), " << day << " day(s), " << hour << " hour(s), " << minute << " minute(s)" << endl;
            }
            else {
                cout << "Net time: " << week << " week(s), " << day << " day(s), " << hour << " hour(s), " << minute << " minute(s)" << endl;
            }
        }
        else {
            cout << "Net time: " << day << " day(s), " << hour << " hour(s), " << minute << " minute(s)" << endl;
        }
    }
    else {
        cout << "Net time: " << temp_time << " hour(s), " << minute << " minute(s)" << endl;
    }

    cout << "<-------------------------------------------------->" << endl;
}
