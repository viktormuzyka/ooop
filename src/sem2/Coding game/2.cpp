#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y 
    string ans;
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    // game loop
    while (1) {
        //cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
        ans= "";
        //cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();


        if (light_y<initial_ty) {
            ans += "N";
            initial_ty--;
        } else if (light_y>initial_ty) {
            ans += "S";
            initial_ty++;
        } else {
            // nothing
        }

         if (light_x<initial_tx) {
            ans += "W";
            initial_tx--;
        } else  if (light_x>initial_tx){
            ans += "E";
            initial_tx++;
        } else {
            //nothing
        }

        /*if (abs(light_y-initial_ty)==abs(light_x-initial_tx)) {
            if ((light_y-initial_ty>0) and(light_x-initial_tx>0)){
                ans = "NE";
            } else if ((light_y-initial_ty>0) and(light_x-initial_tx<0)){
                ans = "NW";
            } else if ((light_y-initial_ty<0) and(light_x-initial_tx>0)){
                ans = "SE";
            } else if ((light_y-initial_ty<0) and(light_x-initial_tx>0)){
                ans = "SW";
            }
        
            // nothing
        }*/
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << ans << endl;
    }
}
