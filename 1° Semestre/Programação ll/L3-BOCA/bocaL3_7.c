#include <stdio.h>
#include <stdlib.h>

int Area_Total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    int area1, area2, area3=0, areaTotal;
    
    
    area1= Area(r1_x1, r1_y1, r1_x2, r1_y2);
    area2= Area(r2_x1, r2_y1, r2_x2, r2_y2);
    
    if(r2_x1 < r2_x2 && r2_y1 < r1_y2){
        area3= Area(r2_x1, r2_y1, r1_x2, r1_y2);
    }
    areaTotal=area1+area2-area3;
    return areaTotal;
}

int Area(int x1, int y1, int x2, int y2){
    int areaX;
    
    areaX= (x2-x1)*(y2-y1);
    return areaX;
}

int main(int argc, char** argv) {
    int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2;
    int areaTotal;
    
    scanf("%d%d%d%d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d%d%d%d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);
    
    // <editor-fold defaultstate="collapsed" desc="comment">
    areaTotal = // </editor-fold>
Area_Total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);
    printf("RESP:%d", areaTotal);
    return (EXIT_SUCCESS);
}

