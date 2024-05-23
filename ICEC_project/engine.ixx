export module engine;

export import std;

using
std::cout, std::cin,
std::array,
std::string,
std::fixed,
std::setprecision;

export class ENGINE
{
  const array<float, 13> const_calc_nums //CONSTANT NUMBERS USED FOR DIFFERENT CALCULATIONS
  {
    3.14f,
    0.1f,
    0.001225f,
    0.01f,
    0.5f,
    2.0f,
    12.7f,
    14.7f,
    60.0f,
    0.7457f,
    1.341f,
    100.00f,
    5252.0f,
  };

public: //POINTERS TO CONST_CALC_NUMS
  const float* const PI       = &const_calc_nums[0];
  const float* const p_1      = &const_calc_nums[1];
  const float* const p_001225 = &const_calc_nums[2];
  const float* const p_01     = &const_calc_nums[3];
  const float* const p_5      = &const_calc_nums[4];
  const float* const _2       = &const_calc_nums[5];
  const float* const _12_7    = &const_calc_nums[6];
  const float* const _14_7    = &const_calc_nums[7];
  const float* const _60      = &const_calc_nums[8];
  const float* const p_745    = &const_calc_nums[9];
  const float* const _1_341   = &const_calc_nums[10];
  const float* const _100     = &const_calc_nums[11];
  const float* const _5252    = &const_calc_nums[12];
  //________________________________________________________

private:
  array<float, 9> engine //ARRAY FOR ENGINE MAIN PARAMETERS
  {
    0.0f, //[0] = ONE RPM KW
    0.0f, //[0] = ONE RPM HP
    0.0f, //[0] = GROSS KW
    0.0f, //[1] = NETO KW
    0.0f, //[2] = GROSS HP
    0.0f, //[3] = NETO HP
    0.0f, //[4] = CAPACITY
    0.0f, //[5] = PISTON SPEED
    0.0f, //[6] = FUEL BURN
  };

public: //POINTERS TO ENGINE ARRAY
  float* const one_rpm_kw  = &engine[0];
  float* const one_rpm_hp  = &engine[1];
  float* const GROSS_KW    = &engine[2];
  float* const NETO_KW     = &engine[3];
  float* const GROSS_HP    = &engine[4];
  float* const NETO_HP     = &engine[5];
  float* const capacity    = &engine[6];
  float* const piston_spd  = &engine[7];
  float* const fuel_burn_h = &engine[8];  
  //_________________________________________________________

private:
  array<float, 7> engine_calc //
  {       
    0.0f, //[0] = BORE
    0.0f, //[1] = STROKE
    0.0f, //[2] = CYLINDER COUNT
    0.0f, //[3] = RPM
    0.0f, //[4] = EFFICIENCY
    0.0f, //[5] = EFFICIENCY * 0.01
    0.0f, //[6] = FUEL KG   
  };

public: //POINTERS TO ENGINE_CALC ARRAY      
  float* const bore       = &engine_calc[0];
  float* const stroke     = &engine_calc[1];
  float* const cyl_cnt    = &engine_calc[2];
  float* const rpm        = &engine_calc[3];
  float* const efficiency = &engine_calc[4];
  float* const eff_001    = &engine_calc[5];
  float* const fuel_kg    = &engine_calc[6];  
  //____________________________________________________________
  
  const char* txt_selection = "SELECTION";
  const char* txt_bore = "ENTER BORE IN mm";
  const char* txt_stroke = "ENTER STROKE IN mm";
  const char* txt_cyl_cnt = "ENTER CYLINDER COUNT";
  const char* txt_rpm = "ENTER RPM";
  const char* txt_efficiency = "ENTER EFFICIENCY PERCENTAGE";
  const char* txt_liters = "ENTER ENGINE LITERS";
  const char* txt_net_KW = "ENTER NET POWER IN KW";
  const char* txt_net_HP = "ENTER NET POWER IN HP";
  const char* txt_KW_or_HP = "PRESS [ 1 ] FOR KW OR [ 2 ] FOR HP\n";

  const char* err_LEN = "input INVALID: LENGTH";
  const char* err_NAN = "input INVALID: NaN";
  const char* err_INT = "input INVALID: NOT A INTEGER";
  const char* err_PERIOD = "input INVALID: PERIODS";
  const char* err_MINMAX = "input INVALID: MIN / MAX VALUE";
  //_____________________________________________________________  

  float selection{ 0.0f };    //VARIABLE FOR SELECTIONS 
  float* sel = &selection; //+ POINTER TO IT

  void zeros() //ENGINE & ENGINE_CALC ARRAYS ZEROING
  {
    engine.fill(0);
    engine_calc.fill(0);
  }

  static void menu_text(bool main_menu = true)
  {
    if (main_menu)
    {
      cout
        << "\n"
        << "======================================================================\n"
        << "PRESS [ 1 ] to enter BORE | STROKE | CYLINDER COUNT | RPM | EFFICIENCY\n"
        << "PRESS [ 2 ] to enter ENGINE LITER  | RPM                              \n"
        << "PRESS [ 3 ] to enter ENGINE LITER | NETO POWER | RPM                  \n"
        << "PRESS [ 0 ] to EXIT                                                   \n"
        << "======================================================================\n";
    }

    else
    {
      cout
        << "\n"
        << "=========================================\n"
        << "PRESS [ 1 ] to CHANGE BORE               \n"
        << "PRESS [ 2 ] to CHANGE STROKE             \n"
        << "PRESS [ 3 ] to CHANGE CYLINDER COUNT     \n"
        << "PRESS [ 4 ] to CHANGE ENGINE RPM         \n"
        << "PRESS [ 5 ] to CHANGE EFFICIENCY         \n"
        << "PRESS [ 6 ] to MAIN MENU                 \n"
        << "=========================================\n\n";
    }
  }

  void input(float* target, const char* text, float min_len, float max_len, double min_val, double max_val, bool isINT = false)
  {
    cout << text << "\n";

    bool valid = false;

    do
    {
      bool dot = false;

      string c_input = "";
      cin >> c_input;
      float inputLength = (float)c_input.length();

      if (inputLength < min_len || inputLength > max_len) cout << err_LEN << "\n" << text << "\n";
      else
      {
        for (const char& i : c_input)
        {
          if (!(i >= 48 && i <= 57 || i == 46)) { cout << err_NAN << "\n" << text << "\n"; valid = false; break; }
          if (i == 46 && isINT == true) { cout << err_INT << "\n" << text << "\n"; valid = false; break; }
          if (i == 46 && dot == true) { cout << err_PERIOD << "\n" << text << "\n"; valid = false; break; }
          if (i == 46 && dot == false) dot = true;

          valid = true;
        }

        if (valid)
        {
          float input = stof(c_input);
          if (!(input <= max_val && input >= min_val)) { valid = false; cout << "err_minmaxV\n" << text << "\n"; }
          else *target = input;
        }
      }

    } while (!valid);
  } 

  void calculations(float num) //calculations done depending menu selection
  {
    if (num == 1.0f)
    {
      *capacity = *PI * (((*bore * *p_5) * (*bore * *p_5)) * *p_01) * (*stroke * *p_01) * *cyl_cnt * *p_01;
      *piston_spd = (*_2 * *stroke * *p_1) * *p_01 * *rpm / *_60;
    }

    *eff_001 = *efficiency * *p_01;
    *fuel_kg = *capacity * *p_5 * *p_001225 / *_14_7;
    *one_rpm_kw = *fuel_kg * *_12_7 * *_60;
    *one_rpm_hp = *one_rpm_kw * *_1_341;
    *fuel_burn_h = *fuel_kg * *_60 * *rpm * *_1_341;
    *GROSS_KW = *one_rpm_kw * *rpm;
    *GROSS_HP = *GROSS_KW * *_1_341;

    if (num != 3.0f)
    {
      *NETO_KW = *GROSS_KW * *eff_001;
      *NETO_HP = *NETO_KW * *_1_341;
    }

    if (num == 3.0f)
    {
      if (*sel == 1) *NETO_HP = *NETO_KW * *_1_341;
      else           *NETO_KW = *NETO_HP * *p_745;

      *efficiency = *NETO_KW / *GROSS_KW * *_100;
    }
  }

  void answer(bool pistonspd = false) const //only first menu selection can calculate piston speed
  {
    cout
      << fixed << setprecision(2) << "\n"
      << "ENGINE SIZE IN LITERS\t" << *capacity
      << "\n@ " << *rpm << " rpm\t\t" << "GROS POWER\t" << *GROSS_KW << " KW(" << *GROSS_HP << " HP)"
      << "\n\t\t\tNET POWER\t" << *NETO_KW << " KW ( " << *NETO_HP << " HP)\n";

    if (pistonspd) cout << "PISTON SPEED\t\t@ " << *rpm << " rpm -" << "\t" << *piston_spd << " m/s\n";

    cout << "EFFICIENCY\t\t" << *efficiency << " %\nFUEL BURN IN HOUR\t" << *fuel_burn_h << " LITERS\n";
  }

  const array<float, 10> coefficient = { 0.7f, 0.73f, 0.77f, 0.8f, 0.82f, 0.83f, 0.81f, 0.78f, 0.75f, 0.72f };

  void horsepower_graph()
  {
    cout << "\nHP - 0\tTQ - X\n";
    
    float maxTQ = (*NETO_HP * *_5252 / *rpm);
    int rows = int(maxTQ) / 20;

    for (int i{ rows + 1 }; i > 0; i--)
    {
      cout << "\n";
      cout << i * 20 << "\t";
      
      for (int r = 1000; r <= *rpm; r += 500)
      {
        int s{ 0 };
        int HP = int(*one_rpm_hp * r * *eff_001 * coefficient[s]);
        int TQ = int(HP * *_5252 * coefficient[s] / *rpm);
        

        if (TQ >= 20 * i && TQ < 20 * (i + 1))
          cout << " X ";
        else cout << "   ";

        if (HP >= 20 * i && HP < 20 * (i + 1))
          cout << " 0 ";
        else cout << "   ";
        
        if (r % 1000 == 0) ++s;
      }

    }
    cout << "\n";

  }

};