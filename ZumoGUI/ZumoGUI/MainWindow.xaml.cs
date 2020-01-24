using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.IO.Ports;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ZumoGUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort mySerialPort = new SerialPort("COM5", 9600);
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnW_Click(object sender, RoutedEventArgs e)
        {

             mySerialPort.Open();
             mySerialPort.Write("W");
             mySerialPort.Close();

        }

        private void btnA_Click(object sender, RoutedEventArgs e)
        {
            mySerialPort.Open();
            mySerialPort.Write("A");
            mySerialPort.Close();
        }

        private void btnS_Click(object sender, RoutedEventArgs e)
        {
            mySerialPort.Open();
            mySerialPort.Write("S");
            mySerialPort.Close();
        }

        private void btnD_Click(object sender, RoutedEventArgs e)
        {
            mySerialPort.Open();
            mySerialPort.Write("D");
            mySerialPort.Close();
        }

        private void output_TextChanged(object sender, TextChangedEventArgs e)
        {
            string test = output.Text;


            switch (test)
            {
                case "w": case "W":
                mySerialPort.Open();
                mySerialPort.Write("W");
                mySerialPort.Close();
                output.Text = String.Empty;
                break;

                case "a": case "A":
                mySerialPort.Open();
                mySerialPort.Write("A");
                mySerialPort.Close();
                output.Text = String.Empty;
                break;

                case "s": case "S":
                mySerialPort.Open();
                mySerialPort.Write("S");
                mySerialPort.Close();
                output.Text = String.Empty;
                break;

                case "d": case "D":
                mySerialPort.Open();
                mySerialPort.Write("D");
                mySerialPort.Close();
                output.Text = String.Empty;
                break;

                case "c": case "C":
                mySerialPort.Open();
                mySerialPort.Write("C");
                mySerialPort.Close();
                output.Text = String.Empty;
                break;
            }         
        }
    }
}
