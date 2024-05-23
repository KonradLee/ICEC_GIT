import engine;

import std;
using
std::cout,
std::cin,
std::array,
std::string;


ENGINE eng;

int main()
{
  do
  {
    eng.menu_text();
    eng.zeros();

    eng.input(eng.sel, eng.txt_selection, 1, 1, 0, 3, true);

    if (*eng.sel == 1.0f)
    {
      eng.input(eng.bore, eng.txt_bore, 1, 5, 1, 999);
      eng.input(eng.stroke, eng.txt_stroke, 1, 5, 1, 999);
      eng.input(eng.cyl_cnt, eng.txt_cyl_cnt, 1, 2, 1, 99, true);
      eng.input(eng.rpm, eng.txt_rpm, 1, 5, 1, 99999, true);
      eng.input(eng.efficiency, eng.txt_efficiency, 1, 3, 1, 100, true);

      eng.calculations(*eng.sel);
      eng.answer(true);

      do
      {
        eng.menu_text(false);
        eng.input(eng.sel, eng.txt_selection, 1, 1, 1, 6, true);
        if (*eng.sel == 6) break;
        else
        {
          if (*eng.sel == 1.0f) eng.input(eng.bore, eng.txt_bore, 1, 5, 1, 999);
          else if (*eng.sel == 2.0f) eng.input(eng.stroke, eng.txt_stroke, 1, 5, 1, 999);
          else if (*eng.sel == 3.0f) eng.input(eng.cyl_cnt, eng.txt_cyl_cnt, 1, 2, 1, 99, true);
          else if (*eng.sel == 4.0f) eng.input(eng.rpm, eng.txt_rpm, 1, 5, 1, 99999, true);
          else if (*eng.sel == 5.0f) eng.input(eng.efficiency, eng.txt_efficiency, 1, 3, 1, 100, true);

          eng.calculations(1.0f);
          eng.answer(true);
          eng.horsepower_graph();
        }
      } while (*eng.sel != 6.0f);
    }

    if (*eng.sel == 2.0f)
    {
      eng.input(eng.capacity, eng.txt_liters, 1, 4, 0.1f, 99);
      eng.input(eng.rpm, eng.txt_rpm, 1, 5, 1, 99999, true);
      eng.input(eng.efficiency, eng.txt_efficiency, 1, 3, 1, 100, true);

      eng.calculations(*eng.sel);
      eng.answer();
      eng.horsepower_graph();
    }

    if (*eng.sel == 3.0f)
    {
      eng.input(eng.capacity, eng.txt_liters, 1, 4, 0.1f, 99);
      eng.input(eng.rpm, eng.txt_rpm, 1, 5, 1, 99999, true);

      eng.input(eng.sel, eng.txt_KW_or_HP, 1, 1, 1, 2, true);

      if (*eng.sel == 1)
      {
        eng.input(eng.NETO_KW, eng.txt_net_KW, 1, 5, 1, 99999, true);
        eng.calculations(3.0f);
        eng.answer();
      }
      else
      {
        eng.input(eng.NETO_HP, eng.txt_net_HP, 1, 5, 1, 99999, true);
        eng.calculations(3.0f);
        eng.answer();
      }

    }
  } while (*eng.sel != 0);
}