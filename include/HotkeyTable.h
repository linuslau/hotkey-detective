/*!
 * \file    HotkeyTable.h
 * \brief   Contains stuff and definitions related to the UI hotkey table.
 * \author  Itachi
 * \date    2020-12-01
 *
 * The key part of the Hotkey Detective is the table presenting hotkeys and
 * associated processes. All stuff related to this UI component are included in
 * this header file.
 */

#ifndef HOTKEY_DETECTIVE__HOTKEYTABLE_H_
#define HOTKEY_DETECTIVE__HOTKEYTABLE_H_

#include <vector>

#include <windows.h>

#define HOTKEY_LENGTH 32
#define TABLE_COLUMNS 2

/*!
 * \brief This is a helper structure containing entries appearing in the main
 *        table.
 */
struct TableEntry {
  wchar_t hotkey[HOTKEY_LENGTH]; //!< A string with a key combination
  wchar_t processPath[MAX_PATH]; //!< A path to the process
};

/*!
 * \brief A class representing the main table on the GUI.
 *
 * This class should enclose all table related operations, especially: creation
 * and modification.
 */
class HotkeyTable {
 private:
  HWND tableHwnd;                  //!< A windowHandle to the table

  std::vector<TableEntry> entries; //!< A vector of entries displayed on the
                                   //!< list
 protected:
 public:
  /*!
   * \brief Adds a new entry to the table.
   *
   * This method adds a new entry both to the table and to the backing vector.
   *
   * \param[in] hotkey      a string containing the key combination
   * \param[in] processPath a wide string containing a path to the process
   */
  void addEntry(char *hotkey, wchar_t *processPath);

  /*!
   * \brief A WM_NOTIFY handler.
   *
   * This handler should be called at each WM_NOTIFY message received by the
   * parent window.
   *
   * When the parent window requires more data while rendering the table (i.e.
   * when the table has more than one column) it sends WM_NOTIFY message with an
   * LVN_GETDISPINFOW command.
   *
   * \param[in] lParam an lParam of the WM_NOTIFY message
   */
  void handleWmNotify(LPARAM lParam);

  /*!
   * \brief Adds the table to the specified window.
   *
   * This method add the table to the window and initializes its columns.
   *
   * \param[in] parentWindow    a parent to window to add the table to
   * \param[in] hInstance       an HINSTANCE of the process owning the window
   */
  void addToWindow(HWND parentWindow, HINSTANCE hInstance);
};

#endif //HOTKEY_DETECTIVE__HOTKEYTABLE_H_
