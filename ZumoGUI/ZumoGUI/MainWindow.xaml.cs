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
        SerialPort mySerialPort = new SerialPort("COM5", 9600); // Create a serial port to communicate over
        public delegate void NoArgDelegate();

        public MainWindow()
        {
            InitializeComponent();
            mySerialPort.Open();
            mySerialPort.DtrEnable = true;
            mySerialPort.Handshake = Handshake.None;
            mySerialPort.Close();
            
        }
        private void btnW_Click(object sender, RoutedEventArgs e) // If buttonW is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("W"); // Open the serial port, type W and close the port
            txtOutput.Text = txtOutput.Text+ "Forward \n";
            mySerialPort.Close();
            txtOutput.ScrollToEnd();

        }

        private void btnA_Click(object sender, RoutedEventArgs e) // If A button is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("A"); // Open the serial port, type A and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnS_Click(object sender, RoutedEventArgs e) // If buttonS is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("S"); // Open the serial port, type S and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnD_Click(object sender, RoutedEventArgs e) // If buttonD is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("D"); // Open the serial port, type D and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnR_Click(object sender, RoutedEventArgs e) // If buttonR is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("R"); // Open the serial port, type R and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();

        }

        private void btnL_Click(object sender, RoutedEventArgs e) // If buttonL is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("L"); // Open the serial port, type L and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();

        }
        private void btnManualCorridor_Click(object sender, RoutedEventArgs e) // If button ManualCorridor is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("C"); // Open the serial port, type C and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnAutoCorridor_Click(object sender, RoutedEventArgs e) // If button AutoCorridor is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("X"); // Open the serial port, type X and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnDetector_Click(object sender, RoutedEventArgs e) // If button Detector is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("Z"); // Open the serial port, type Z and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();
        }

        private void btnB_Click(object sender, RoutedEventArgs e) // If buttonB is clicked
        {
            mySerialPort.Open();
            mySerialPort.Write("B"); // Open the serial port, type B and close the port
            mySerialPort.Close();
            txtOutput.ScrollToEnd();

        }

        private void txtInput_TextChanged(object sender, TextChangedEventArgs e) // If txtInput's (TYPE CONTROLS) text is changed
        {
            string input = txtInput.Text; //Assign string input to the text written in txtInput
            txtOutput.ScrollToEnd();

            switch (input) //Switch case using string input
            {
                case "w": case "W": //If input = W
                mySerialPort.Open();
                mySerialPort.Write("W");  // Open the serial port, type W and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                txtOutput.Text = txtOutput.Text + "Forward \n";
                break;

                case "a": case "A": //If input = A
                    mySerialPort.Open();
                mySerialPort.Write("A");  // Open the serial port, type A and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "s": case "S": //If input = S
                    mySerialPort.Open();
                mySerialPort.Write("S"); // Open the serial port, type S and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "d": case "D": //If input = D
                    mySerialPort.Open();
                mySerialPort.Write("D"); // Open the serial port, type D and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "c": case "C": //If input = C
                    mySerialPort.Open();
                mySerialPort.Write("C"); // Open the serial port, type WCand close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "l": case "L": //If input = L
                    mySerialPort.Open();
                mySerialPort.Write("L"); // Open the serial port, type L and close the port;
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "r": case "R": //If input = R
                    mySerialPort.Open();
                mySerialPort.Write("R"); // Open the serial port, type R and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;

                case "b": case "B": //If input = B
                    mySerialPort.Open();
                mySerialPort.Write("B"); // Open the serial port, type B and close the port
                mySerialPort.Close();
                txtInput.Text = String.Empty;
                break;
            }         
        }


    }
}
