import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial

class UltrasoundNode(Node):

    def __init__(self):
        super().__init__('ultrasound_node')
        self.publisher_ = self.create_publisher(String, 'ultrasound_topic', 10)

        try:
            self.serial_port = serial.Serial('/dev/ttyACM0', 9600, timeout=2)
            self.get_logger().info('Serial port /dev/ttyACM0 opened successfully.')
        except serial.SerialException as e:
            self.get_logger().error(f'Could not open serial port: {e}')
            self.get_logger().error('Is the Arduino plugged in? Is the port correct?')
            rclpy.shutdown()
            return

        timer_period = 0.1  
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        if (self.serial_port.in_waiting > 0):
            try:
                data_line = self.serial_port.readline().decode('ascii').strip()
                msg = String()
                msg.data = data_line
                self.publisher_.publish(msg)
                self.get_logger().info('Publishing: "%s"' % data_line)
            except UnicodeDecodeError:
                self.get_logger().warn('Could not decode serial data, skipping line.')
            except Exception as e:
                self.get_logger().error(f'Error in timer_callback: {e}')

def main(args=None):
    rclpy.init(args=args)
    ultrasound_node = UltrasoundNode()

    if rclpy.ok():
        try:
            rclpy.spin(ultrasound_node)
        except KeyboardInterrupt:
            pass 
        finally:
            ultrasound_node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    main()