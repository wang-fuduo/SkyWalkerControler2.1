#include "bsp_can.h"

// CAN过滤器初始化
// 虽然不需要过滤任何ID，但是过滤器关乎到开启中断、使能CAN等功能
void BSP_FDCAN_Init()
{
  FDCAN_FilterTypeDef FDCAN1_FilterConfig;

  FDCAN1_FilterConfig.IdType = FDCAN_STANDARD_ID;
  FDCAN1_FilterConfig.FilterIndex = 0;
  FDCAN1_FilterConfig.FilterType = FDCAN_FILTER_MASK;
  FDCAN1_FilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
  FDCAN1_FilterConfig.FilterID1 = 0x00000000;
  FDCAN1_FilterConfig.FilterID2 = 0x00000000;

  HAL_FDCAN_ConfigFilter(&hfdcan1, &FDCAN1_FilterConfig);

  HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);

  HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

  HAL_FDCAN_Start(&hfdcan1);


  FDCAN_FilterTypeDef FDCAN2_FilterConfig;

  FDCAN2_FilterConfig.IdType = FDCAN_EXTENDED_ID;
  FDCAN2_FilterConfig.FilterIndex = 0;
  FDCAN2_FilterConfig.FilterType = FDCAN_FILTER_MASK;
  FDCAN2_FilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
  FDCAN2_FilterConfig.FilterID1 = 0x00000000;
  FDCAN2_FilterConfig.FilterID2 = 0x00000000;

  HAL_FDCAN_ConfigFilter(&hfdcan2, &FDCAN2_FilterConfig);

  HAL_FDCAN_ConfigGlobalFilter(&hfdcan2, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);

  HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO1_NEW_MESSAGE, 0);

  HAL_FDCAN_EnableTxDelayCompensation(&hfdcan2);

  HAL_FDCAN_ConfigTxDelayCompensation(&hfdcan2, 14, 14);

  HAL_FDCAN_Start(&hfdcan2);


  FDCAN_FilterTypeDef FDCAN3_FilterConfig;

  FDCAN3_FilterConfig.IdType = FDCAN_STANDARD_ID;
  FDCAN3_FilterConfig.FilterIndex = 0;
  FDCAN3_FilterConfig.FilterType = FDCAN_FILTER_MASK;
  FDCAN3_FilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
  FDCAN3_FilterConfig.FilterID1 = 0x00000000;
  FDCAN3_FilterConfig.FilterID2 = 0x00000000;

  HAL_FDCAN_ConfigFilter(&hfdcan3, &FDCAN3_FilterConfig);

  HAL_FDCAN_ConfigGlobalFilter(&hfdcan3, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);

  HAL_FDCAN_ActivateNotification(&hfdcan3, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

  HAL_FDCAN_Start(&hfdcan3);
}

// CAN发送头结构体配置
FDCAN_TxFrame_TypeDef hfdcan1TxFrame = {
  .hcan = &hfdcan1,  // CAN1发送
  .Header.IdType = FDCAN_STANDARD_ID,  // 标准ID
  .Header.TxFrameType = FDCAN_DATA_FRAME,  // 数据帧
  .Header.DataLength = FDCAN_DLC_BYTES_8,  // 8个字节
  .Header.ErrorStateIndicator =  FDCAN_ESI_ACTIVE,  // CAN发送错误指示
  .Header.BitRateSwitch = FDCAN_BRS_OFF,  // 波特率切换关闭
  .Header.FDFormat =  FDCAN_CLASSIC_CAN,  // 经典CAN模式
  .Header.TxEventFifoControl =  FDCAN_NO_TX_EVENTS,  // 不存储发送事件
  .Header.MessageMarker = 0,  // 消息标记0
};
FDCAN_TxFrame_TypeDef hfdcan2TxFrame = {
  .hcan = &hfdcan2,  // CAN1发送
  .Header.IdType = FDCAN_EXTENDED_ID,  // 扩展ID
  .Header.TxFrameType = FDCAN_DATA_FRAME,  // 数据帧
  .Header.DataLength = FDCAN_DLC_BYTES_8,  // 8个字节
  .Header.ErrorStateIndicator =  FDCAN_ESI_ACTIVE,  // CAN发送错误指示
  .Header.BitRateSwitch = FDCAN_BRS_OFF,  // 波特率切换关闭
  .Header.FDFormat =  FDCAN_CLASSIC_CAN,  // 经典CAN模式
  .Header.TxEventFifoControl =  FDCAN_NO_TX_EVENTS,  // 不存储发送事件
  .Header.MessageMarker = 0,  // 消息标记0
};
FDCAN_TxFrame_TypeDef hfdcan3TxFrame = {
  .hcan = &hfdcan3,  // CAN1发送
  .Header.IdType = FDCAN_STANDARD_ID,  // 标准ID
  .Header.TxFrameType = FDCAN_DATA_FRAME,  // 数据帧
  .Header.DataLength = FDCAN_DLC_BYTES_8,  // 8个字节
  .Header.ErrorStateIndicator =  FDCAN_ESI_ACTIVE,  // CAN发送错误指示
  .Header.BitRateSwitch = FDCAN_BRS_OFF,  // 波特率切换关闭
  .Header.FDFormat =  FDCAN_CLASSIC_CAN,  // 经典CAN模式
  .Header.TxEventFifoControl =  FDCAN_NO_TX_EVENTS,  // 不存储发送事件
  .Header.MessageMarker = 0,  // 消息标记0
};