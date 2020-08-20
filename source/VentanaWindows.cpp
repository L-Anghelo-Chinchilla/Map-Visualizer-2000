#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "logic.cpp"
#include <string>
#include <thread>
#include <random>
#include <Time.h>

using namespace Gdiplus;

#pragma comment (lib,"Gdiplus.lib")

VOID OnPaint(HDC& hdc);

VOID OnPaint(HDC& hdc,Point mejorRuta[] , int tam ,int r,int g,int b ) 
{
    Graphics graphics(hdc);
    Pen pen(Color(255, r,g,b), 5);
    pen.SetEndCap(LineCapArrowAnchor);
    pen.SetStartCap(LineCapRoundAnchor);
   // Sleep(500);
    graphics.DrawLines(&pen,mejorRuta , tam);
    //Sleep(500);
}

VOID OnPaint(HDC& hdc )
{ 
        Graphics graphics(hdc);
        Pen pen(Color(255, 0, 0, 255), 2.5);
        pen.SetColor(Color());
        Rect rect[48] = { Rect(100, 100, 30, 30), Rect(150, 100, 30, 30), Rect(200, 100, 30, 30), Rect(250, 100, 30, 30), Rect(300, 100, 30, 30),Rect(350, 100, 30, 30),Rect(400, 100, 30, 30),Rect(450, 100, 30, 30),
                          Rect(100, 150, 30, 30), Rect(150, 150, 30, 30), Rect(200, 150, 30, 30), Rect(250, 150, 30, 30), Rect(300, 150, 30, 80), Rect(350, 150, 30, 30),Rect(400, 150, 30, 30),Rect(450,150, 30, 30),
                          Rect(100, 200, 30, 30),Rect(150, 200, 30, 30),Rect(200, 200, 80, 30),                                              Rect(350, 200, 30, 30),Rect(400, 200, 30, 30),Rect(450, 200, 30, 30),
                          Rect(100, 250, 30, 30),Rect(150, 250, 30, 30),Rect(200, 250, 30, 30),Rect(250, 250, 30, 30),Rect(300, 250, 30, 30),Rect(350, 250, 80, 30),Rect(450, 250, 30, 30),
                          Rect(100, 300, 30, 30),Rect(150, 300, 30,30), Rect(200, 300, 30, 30),Rect(250, 300, 30, 30),Rect(300, 300, 30, 30),Rect(350, 300, 30, 30),Rect(400, 300, 30, 30),Rect(450, 300, 30, 30),
                          Rect(100, 350, 30, 30),Rect(150, 350, 30, 30),Rect(200, 350, 30, 30),Rect(250, 350, 30, 30),Rect(300, 350, 30, 30),Rect(350, 350, 30, 30),Rect(400, 350, 30, 30),Rect(450, 350, 30, 30)
         ,Rect(75,225,20,35), Rect(270,75,35,20) ,Rect(425,385,35,20)       };
        graphics.DrawRectangles(&pen, rect, 48);
        Brush* brush = new  SolidBrush(Color().Aquamarine);
        graphics.FillRectangles(brush, rect, 48);
        pen.SetEndCap(LineCapArrowAnchor);
       
        graphics.DrawLine(&pen, 100, 137, 120, 137);
        graphics.DrawLine(&pen, 137, 100, 137, 120);
        graphics.DrawLine(&pen, 237, 100, 237, 120);
        graphics.DrawLine(&pen, 287, 100, 287, 120);
        graphics.DrawLine(&pen, 337, 100, 337, 120);
        graphics.DrawLine(&pen, 480, 137, 460, 137);
        graphics.DrawLine(&pen, 480, 187, 460, 187);
        graphics.DrawLine(&pen, 280, 187, 260, 187);
        graphics.DrawLine(&pen, 100, 237, 120, 237);
        graphics.DrawLine(&pen, 480, 287, 460, 287);
        graphics.DrawLine(&pen, 437, 380, 437, 360);
        graphics.DrawLine(&pen, 387, 380, 387, 360);
        graphics.DrawLine(&pen, 337, 380, 337, 360);
        graphics.DrawLine(&pen, 237, 380, 237, 360);
        graphics.DrawLine(&pen, 187, 380, 187, 360);
        graphics.DrawLine(&pen, 100, 337, 120, 337);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM );

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    HWND                hWnd;
    MSG                 msg;
    WNDCLASS            wndClass;
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;
    HWND hwndButton;
    HWND etiqueta;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("Vizualizador de mapa 2000");

    RegisterClass(&wndClass);
    
    hWnd = CreateWindow(
        TEXT("Vizualizador de mapa 2000"),  
        TEXT("Vizualizador de mapa 2000"),  
        (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ),
        CW_USEDEFAULT,           
        CW_USEDEFAULT,            
        640,530,                      
        NULL,                     
        NULL,                     
        hInstance,               
        NULL);                    
     hwndButton = CreateWindow(L"STATIC",L" Graficar Rutas",WS_VISIBLE|WS_CHILD|WS_BORDER , 500,450,101,23,hWnd ,NULL , (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),NULL);
    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);
    
    etiqueta = CreateWindow(L"STATIC",L"Presione una parada o  presione el botón",WS_VISIBLE|WS_CHILD , 10,400,400,80,hWnd ,NULL , (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),NULL);
  
    int arr[4][4];
    vector<vector<int> > lista{ {1,7},{0,2},{1,3,9},{2,4,10},{3,5,11},{4,6},{5},
                               {14},{1,7},{8},{9,17},{4,18},{11},{6,12},
                               {15,21},{8,16},{17},{18,24},{11,19,25},{20},{13},
                               {28},{15,21},{16,22},{23,31},{18,24,32},{25},{20,26},
                               {29},{22,30},{23,31},{32},{25,33},{26,34},{27} };
    Grafo grafo(35, false, lista);
    vector <int> mejor , rutaAi,rutaBi,rutaCi;
    vector<vector<int> > rutas;
    Point rutaA[100];
    Point rutaB[1];
    Point rutaC[1];
    int numRuta = -1,res, estado = 0,posx , posy ,desde,hasta ;
    
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        int x, y;
        res = DispatchMessage(&msg);
        if (res == 64)
        {
            x = LOWORD(msg.lParam);
            y = HIWORD(msg.lParam);
            if (estado == 2)
            {
                InvalidateRect(hWnd, NULL, true);
                SetWindowTextA(etiqueta, "Presione un punto de partida y un destino.");
                estado = 0;
            }
            else if (x >= 75 && x <= 460 && y >= 75 && y <= 405)
            {
                if (estado == 0)
                {
                    desde = grafo.pix2ver(x, y);
                    if (desde != -1) {
                        estado++;
                        
                        SetWindowTextA(etiqueta, "Presione una interseccion de calles." );
                    }
                }
                else if (estado == 1)
                {
                    hasta = grafo.pix2ver(x, y);
                    if (hasta != -1) {
                        pair<Point*, int> mejorRuta = grafo.getMejorRuta(desde, hasta);
                        InvalidateRect(hWnd, NULL, true);
                        HDC          hdc;
                        PAINTSTRUCT  ps;
                        hdc = BeginPaint(hWnd, &ps);
                        OnPaint(hdc, mejorRuta.first, mejorRuta.second,51, 205, 205);
                        OnPaint(hdc);
                        SetWindowTextA(etiqueta, "Ruta trazada. Presione la pantalla para trazar ruta nueva.");
                        estado++;
                    }
                }
            }
            else if (x >= 500 && x <= 600 && y >= 450 && y <= 473) 
            {
                estado = 0;
                if (numRuta == -1) {
                    SetWindowTextA(etiqueta, "Calculando rutas...");
                    grafo.getRutasSimul(rutas);
                    numRuta = 0;
                }
                if (numRuta >= 0)
                {
                    if (numRuta >= rutas.size())
                        numRuta = 11;
                    string g;
                    pair<Point*, int> rutaA = grafo.getPuntos(&(rutas[++numRuta]));
                    g += "B:" +grafo.cadena(&(rutas[numRuta])) ;
                    pair<Point*, int> rutaB = grafo.getPuntos(&(rutas[++numRuta]));
                    g += "C:"+grafo.cadena(&(rutas[numRuta]));
                    pair<Point*, int> rutaC = grafo.getPuntos(&(rutas[++numRuta]));
                    g += "A:"+grafo.cadena(&(rutas[numRuta]));
                    HDC          hdc;
                    PAINTSTRUCT  ps;
                    InvalidateRect(hWnd, NULL, true);
                    hdc = BeginPaint(hWnd, &ps);

                    OnPaint(hdc);
                    OnPaint(hdc, rutaA.first, rutaA.second, 255, 0, 0);
                    Sleep(900);
                    OnPaint(hdc, rutaB.first, rutaB.second, 0, 255, 0);
                    Sleep(900);
                    OnPaint(hdc, rutaC.first, rutaC.second, 0, 0, 255);
                    Sleep(900);
                    string s = "posiblidad " + to_string(numRuta / 3) + " de " + to_string(rutas.size() / 3) + '\n' + g;
                    SetWindowTextA(etiqueta, s.c_str());
                    numRuta *= 3;
                }
            }
            else SetWindowTextA(etiqueta, "Por favor , presione una intereseccion entre calles =)");

        }
    }
    SetWindowTextA(etiqueta, "Bueno, ADIOOOOOOOOOOSS!!!");
    GdiplusShutdown(gdiplusToken);
    return msg.wParam;
}  

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam )
{
    HDC          hdc;
    PAINTSTRUCT  ps;
    int res2;
    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            OnPaint(hdc);
            
            EndPaint(hWnd, &ps);
            return 0;
        case WM_DESTROY:
            SetWindowText(hWnd, L"Bueno, ADIOOOOOOOOOOSS!!! =)");
            PostQuitMessage(0);
            return 0;
        case WM_COMMAND:
              res2 = LOWORD(lParam);
            return res2;
        case   WM_LBUTTONDOWN:
            return 64;
        default:
         return DefWindowProc(hWnd, message, wParam, lParam);
    }
} 