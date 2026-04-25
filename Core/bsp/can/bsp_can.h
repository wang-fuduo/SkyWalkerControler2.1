//
// Created by 24699 on 26-4-18.
//

#ifndef BSP_CAN_H
#define BSP_CAN_H

#include "fdcan.h"

void BSP_FDCAN_Init();  // CAN过滤器初始化

typedef struct {
    FDCAN_HandleTypeDef *hcan;
    FDCAN_TxHeaderTypeDef Header;
    uint8_t				Data[8];
}FDCAN_TxFrame_TypeDef;

extern FDCAN_TxFrame_TypeDef hfdcan1TxFrame;
extern FDCAN_TxFrame_TypeDef hfdcan2TxFrame;
extern FDCAN_TxFrame_TypeDef hfdcan3TxFrame;

typedef struct {
    FDCAN_HandleTypeDef *hcan;
    FDCAN_RxHeaderTypeDef Header;
    uint8_t 			Data[8];
} FDCAN_RxFrame_TypeDef;

#endif //BSP_CAN_H
