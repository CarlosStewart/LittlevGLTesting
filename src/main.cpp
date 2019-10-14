#include "main.h"

pros::Motor rightRoller(1, true);
pros::Motor leftRoller(2, false);

int num = 0;
static lv_res_t action1(lv_obj_t *btn) {
  uint8_t id = lv_obj_get_free_num(btn);
  num++;
  if (num % 2 != 0) {
    rightRoller.move_velocity(200);
    leftRoller.move_velocity(200);
  } else {
    rightRoller.move_velocity(0);
    leftRoller.move_velocity(0);
  }

  return LV_RES_OK;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  static lv_style_t tabview_indic_style;
  tabview_indic_style.body.border.color = LV_COLOR_WHITE;
  tabview_indic_style.body.border.width = 4;
  tabview_indic_style.body.border.part = LV_BORDER_FULL;
  tabview_indic_style.body.border.opa = LV_OPA_MAX;
  tabview_indic_style.body.padding.inner = 5;
  tabview_indic_style.body.opa = LV_OPA_MAX;

  static lv_style_t tabview_btn_style;
  lv_style_copy(&tabview_btn_style, &lv_style_plain);
  tabview_btn_style.body.main_color = LV_COLOR_HEX(0xa600ff);
  tabview_btn_style.body.grad_color = LV_COLOR_HEX(0xa600ff);
  tabview_btn_style.text.color = LV_COLOR_WHITE;

  static lv_style_t tabview_btn_tgl_style;
  lv_style_copy(&tabview_btn_tgl_style, &tabview_btn_style);
  tabview_btn_tgl_style.body.border.width = 2;
  tabview_btn_tgl_style.body.border.color = LV_COLOR_WHITE;

  static lv_style_t tabview_btn_pr_style;
  lv_style_copy(&tabview_btn_pr_style, &lv_style_plain);
  tabview_btn_pr_style.body.main_color = LV_COLOR_WHITE;
  tabview_btn_pr_style.body.grad_color = LV_COLOR_WHITE;
  tabview_btn_pr_style.text.color = LV_COLOR_WHITE;

  lv_obj_t *tabview_windows = lv_tabview_create(lv_scr_act(), NULL);
  lv_obj_t *tab_controls = lv_tabview_add_tab(tabview_windows, "Controls");
  lv_obj_t *tab_values = lv_tabview_add_tab(tabview_windows, "Values");
  lv_obj_t *tab_other = lv_tabview_add_tab(tabview_windows, "Other");

  lv_tabview_set_style(tabview_windows, LV_TABVIEW_STYLE_INDIC,
                       &tabview_indic_style);
  lv_tabview_set_style(tabview_windows, LV_TABVIEW_STYLE_BTN_REL,
                       &tabview_btn_style);
  lv_tabview_set_style(tabview_windows, LV_TABVIEW_STYLE_BTN_PR,
                       &tabview_btn_pr_style);
  lv_tabview_set_style(tabview_windows, LV_TABVIEW_STYLE_BTN_TGL_REL,
                       &tabview_btn_tgl_style);
  lv_tabview_set_style(tabview_windows, LV_TABVIEW_STYLE_BTN_TGL_PR,
                       &tabview_btn_pr_style);

  lv_obj_t *btn_run_func1 = lv_btn_create(tab_controls, NULL);
  lv_cont_set_fit(btn_run_func1, true,
                  true); // enable vertical/horizontal resizing
  lv_obj_align(btn_run_func1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 5);
  lv_obj_set_free_num(btn_run_func1, 1); // set a unique number for the button
  lv_btn_set_action(btn_run_func1, LV_BTN_ACTION_CLICK, action1);
  lv_obj_t *label = lv_label_create(btn_run_func1, NULL);
  lv_label_set_text(label, "func1");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  while (true) {
    pros::delay(20);
  }
}
