#include "Node.hpp"
#include <iomanip> 

int         **Node::createFinalGrid() {

    int     **fgrid = new int*[_size];
    int     progress = 0;        
    int     nb = 1;        
    int     i;
    int     j;

	for (int i = 0; i < _size; i++) {
		fgrid[i] = new int[_size];
	}

    while (progress < _size / 2 + 1) {

        i = progress;
        j = progress + 1;

        while (i < _size - progress) {
            fgrid[progress][i] = (nb != _size * _size) ? nb : 0;
            nb++;
            i++;
        }
        while (j < _size - progress) {
            fgrid[j][_size - 1 - progress] = nb;
            nb++;
            j++;
        }
        i = i - 2;
        j = j - 2;
        while (i >= progress) {
            fgrid[_size - progress - 1][i] = (nb != _size * _size) ? nb : 0;
            nb++;
            i--;
        }
        while (j > progress) {
            fgrid[j][progress] = nb;
            nb++;
            j--;
        }
        progress++;
    }
    
    return fgrid;
}