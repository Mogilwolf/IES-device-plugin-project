#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_H_

#include <threadpooling/iprocessable.h>
#include <utils/services/domain/regreaddivider.h>

#include "abstractmodbusasyncclientwrapper.h"
#include <modbuswrappers/export.h>

class MODBUSWRAPPERS_EXPORT ModbusAsyncClientWrapper: public AbstractModbusAsyncClientWrapper {
 public:
  explicit ModbusAsyncClientWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper, int holding_regs_count, int input_regs_count);

  std::string getIP() override;
  int getPort() override;
  int getModbusID() override;

  ErrorCode connect() override;
  ErrorCode disconnect() override;

  ErrorCode isConnected(bool &is_connected) override;
  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id = 1) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id = 1) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id = 1) override;
  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id = 1) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) override;

  void addConnectable(const std::shared_ptr<Connectable> &connectable) override;
  void sendConnectionStatus(bool connection_status) override;

  void process() override;

  const std::vector<uint16_t> &getHoldingRegs();
  const std::vector<uint16_t> &getInputRegs();

 private:
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;

  int _holding_regs_count = 1;
  int _input_regs_count = 1;

  std::vector<uint16_t> _holding_regs;
  std::vector<uint16_t> _input_regs;

  std::shared_ptr<RegReadDivider> _holding_regs_divider = nullptr;
  std::shared_ptr<RegReadDivider> _input_regs_divider = nullptr;

  std::atomic<bool> _is_processed{false};
};


#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_H_
