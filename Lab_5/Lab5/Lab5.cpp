#include "stdafx.h"
#include "Graph.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "������ ����� ��������� ������ � �� ��� (����� �������� �����)" << endl;
    graph.PrimsAlgorithm();
    cout << "\n������ ����� ��������� ������ � �� ��� (����� �������� ��������)" << endl;
    graph.KruskalsAlgoritm();
}