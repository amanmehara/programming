/*
 * BMI Calculator
 * Lab 4
 * 1-10-2017
 */
package driver;

import javax.swing.JOptionPane;

/**
 *
 * @author Fatima Mubeen
 */
public class BMI extends javax.swing.JFrame {
    
    private int age;
    private double heightInMeters;
    private double weightInKg;
    
    
    /**
     * Creates new form BMI
     */
    public BMI() {
        initComponents();
        this.setLocationRelativeTo(null);       //center align the form on screen
        outputPanel.hide();
    }
    
    /**
     * Set age after validation
     */
    private boolean setAge(String a){
        if(!a.matches("[0-9]+")){
            JOptionPane.showMessageDialog(null, "Age must be a positive Integer");
            return false;
        }
        if(Integer.parseInt(a)<1){
            JOptionPane.showMessageDialog(null, "Age must be a positive Integer");
            return false;
        }
        age=Integer.parseInt(a);
        return true;
    }
    
    /**
     * returns age
     */
    private int getAge(){
        return age;
    }
    
    /**
     * Takes height and its unit and convert to height in meters
     */
    private boolean setHeightInMeters(String h,String unit){
        double height=0;
        if(unit.equals("cm")){    
            //conversion from cm to m
            String[] tokens=h.split("."); 
            if(tokens.length>2){
                //checks if there are 2 parts in decimal value 
                JOptionPane.showMessageDialog(null, "More than one decimal point. Enter correct Height");
                return false;
            }
            for(String t:tokens){
                if(!t.matches("[0-9]+")){
                    JOptionPane.showMessageDialog(null, "Height Must Contain digits Only. Enter correct Height");
                    return false;
                }
            }
            height=Double.parseDouble(h);
            heightInMeters=height*(0.01);  // 1cm=0.01m
            return true;
        }
        else {
            /*code below converts ft in to meters*/
            String[] unitTokens=h.split(" ");
            if(unitTokens.length>2){
               /*checs if splited into 2 parts ft & in*/  
               JOptionPane.showMessageDialog(null, "Enter Height in correct format i.e ft in");
               return false; 
            }
            for(String s: unitTokens){
                /*each splited part is tested to be numeric*/
                String[] tokens=s.split(".");
                if(tokens.length>2){
                    JOptionPane.showMessageDialog(null, "More than one decimal point. Enter correct Height");
                    return false;
                }
                for(String t:tokens){
                    if(!t.matches("[0-9]+")){
                        JOptionPane.showMessageDialog(null, "Height Must Contain digits Only. Enter correct Height");
                        return false;
                    }
                } 
            }
            for(int i=0;i<unitTokens.length;i++){
                /*following code gets height in inches*/
                if(i==0)
                    height=Double.parseDouble(unitTokens[i])*12;        //converting foot to inch
                else
                    height=height+Double.parseDouble(unitTokens[i]);    //if inches are provided they are added to get total
            }
            heightInMeters=height*(0.0254);                             //converting inches to meters
        }
        return true;
    }
    
    /**
     * Gives height in meters
     */
    private double getHeightInMeters(){
        return heightInMeters;
    }
    
    /**
     * Takes weight along with units and sets weight in kgs
     */
    private boolean setWeightInKg(String w,String units){
        if(units.equals("kg")||units.equals("lb")){
            /*if the weight is decimal point value it is splitted in 2 parts*/
            String[] tokens=w.split(".");
            if(tokens.length>2){
                JOptionPane.showMessageDialog(null, "More than one decimal point. Enter correct Weight");
                return false;
            }
            for(String t:tokens){
                /*Checking splitted parts to be numeric*/
                if(!t.matches("[0-9]+")){
                    JOptionPane.showMessageDialog(null, "Enter Numeric data in Weight field");
                    return false;
                }
            }
            if(units.equals("kg"))
                weightInKg=Double.parseDouble(w);
            else
                weightInKg=Double.parseDouble(w)*0.4536;    //converting lb to kg
            return true;
        }  
        else{
            /*code below converts st lb to kg*/
            double weightInlb=0;
            String[] unitTokens=w.split(" ");
            if(unitTokens.length>2){
               JOptionPane.showMessageDialog(null, "Enter weight in correct format i.e st lb");
               return false; 
            }
            for(String s: unitTokens){
                String[] tokens=s.split(".");
                if(tokens.length>2){
                    JOptionPane.showMessageDialog(null, "More than one decimal point. Enter correct Weight");
                    return false;
                }
                for(String t:tokens){
                    if(!t.matches("[0-9]+")){
                        JOptionPane.showMessageDialog(null, "Enter Numeric data in Weight field");
                        return false;
                    }
                } 
            }
            for(int i=0;i<unitTokens.length;i++){
                /*following code gets height in inches*/
                if(i==0)
                    weightInlb=Double.parseDouble(unitTokens[i])*14;        
                else
                    weightInlb=weightInlb+Double.parseDouble(unitTokens[i]);
            }
            weightInKg=weightInlb*(0.4535);
        }
        return true;
    }
    
    /**
     *  gives BMI
     */
    private double getBMI(){
        double bmi= weightInKg/(heightInMeters*heightInMeters); // D R Miller Formula
        if(bmi<3)
           outputLabel.setText("Recheck Input Values"); 
        if(bmi<=18.5)
            outputLabel.setText("Time to grab some bites");
        else if(bmi>18.5 && bmi<=25)
            outputLabel.setText("Great Shape");
        else if(bmi>25 && bmi<100)
            outputLabel.setText("Time to Run!");
        else
            outputLabel.setText("Recheck Input Values"); 
        return bmi;
        
    }
    /**
     *  gives ideal weight 
     */
    private double getIdealWeight(String gender){
            /* 
            *ideal weight of 5ft(60 inch) men is 56.2kg
            *and for women its 53.1 kg
            *Other than 5ft height inches over or below
            *are made factor of 1.41 for men and 1.36 for
            *women which are then added to
            *above mentioned ideal weights 
            */
        double idealWeight=0;
        if(gender.equals("Male")){   
            /* calculates ideal weight for males */
            idealWeight=56.2 + (1.41*((heightInMeters*39.3701)-60));          //1 meter=39.3701 inch
        }
        else{
            /* calculates ideal weight for females */
            idealWeight=53.1 + (1.36*((heightInMeters*39.3701)-60));
        }
        return idealWeight;
    }
    
    /**
     *  gives fat% 
     */
    private double getBodyFat(String gender){
            /* 
            *Deurenberg and coworkers formula gives
            *Bodyfat%=(1.20 * BMI) + (0.23 * Age) - (10.8 * Gender) - 5.4 
            *where Gender=1 for males and 0 for females
            *and Child is one having age less than 50
            */
            double bodyFat;
            int Gender;
            if(gender.equals("Male"))
                Gender=1;
            else
                Gender=0;
           
            /*body fat*/
            bodyFat=(1.20 * getBMI()) + (0.23 * age) - (10.8 * Gender) - 5.4;
           
            return bodyFat;
    }
    

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        genderComboBox = new javax.swing.JComboBox<>();
        jLabel5 = new javax.swing.JLabel();
        ageText = new javax.swing.JTextField();
        heightUnitsComboBox = new javax.swing.JComboBox<>();
        jLabel4 = new javax.swing.JLabel();
        heightText = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        weightText = new javax.swing.JTextField();
        weightUnitsComboBox = new javax.swing.JComboBox<>();
        calculateBMIButton = new javax.swing.JButton();
        outputPanel = new javax.swing.JPanel();
        BMIText = new javax.swing.JTextField();
        idealWeightText = new javax.swing.JTextField();
        bodyFatText = new javax.swing.JTextField();
        outputLabel = new javax.swing.JLabel();
        outputLabel1 = new javax.swing.JLabel();
        outputLabel2 = new javax.swing.JLabel();
        outputLabel3 = new javax.swing.JLabel();
        dataStatusLabel = new javax.swing.JLabel();
        jPanel3 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(0, 153, 153));

        jPanel2.setBackground(new java.awt.Color(19, 35, 47));

        jLabel2.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("Gender");

        jLabel3.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(255, 255, 255));

        genderComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Female", "Male" }));
        genderComboBox.setToolTipText("Select Your Gender");

        jLabel5.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("Age");

        heightUnitsComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "cm", "ft  in" }));
        heightUnitsComboBox.setToolTipText("select unit");
        heightUnitsComboBox.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                heightUnitsComboBoxActionPerformed(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("Height");

        jLabel6.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setText("Weight");

        weightUnitsComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "kg", "lb", "st lb" }));

        calculateBMIButton.setBackground(new java.awt.Color(23, 155, 119));
        calculateBMIButton.setFont(new java.awt.Font("Gotham Bold", 0, 24)); // NOI18N
        calculateBMIButton.setForeground(new java.awt.Color(255, 255, 255));
        calculateBMIButton.setText("Calculate BMI");
        calculateBMIButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                calculateBMIButtonMouseClicked(evt);
            }
        });
        calculateBMIButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                calculateBMIButtonActionPerformed(evt);
            }
        });

        outputPanel.setBackground(new java.awt.Color(19, 35, 47));
        outputPanel.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(23, 155, 119)));

        BMIText.setBackground(new java.awt.Color(23, 155, 119));
        BMIText.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        BMIText.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        idealWeightText.setBackground(new java.awt.Color(23, 155, 119));
        idealWeightText.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        idealWeightText.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        bodyFatText.setBackground(new java.awt.Color(23, 155, 119));
        bodyFatText.setFont(new java.awt.Font("Gotham Bold", 0, 18)); // NOI18N
        bodyFatText.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        outputLabel.setBackground(new java.awt.Color(19, 35, 47));
        outputLabel.setForeground(new java.awt.Color(23, 155, 119));
        outputLabel.setText("Ouput");

        outputLabel1.setBackground(new java.awt.Color(19, 35, 47));
        outputLabel1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        outputLabel1.setForeground(new java.awt.Color(23, 155, 119));
        outputLabel1.setText("BMI");

        outputLabel2.setBackground(new java.awt.Color(19, 35, 47));
        outputLabel2.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        outputLabel2.setForeground(new java.awt.Color(23, 155, 119));
        outputLabel2.setText("Ideal Weight");

        outputLabel3.setBackground(new java.awt.Color(19, 35, 47));
        outputLabel3.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        outputLabel3.setForeground(new java.awt.Color(23, 155, 119));
        outputLabel3.setText("Fat%");

        javax.swing.GroupLayout outputPanelLayout = new javax.swing.GroupLayout(outputPanel);
        outputPanel.setLayout(outputPanelLayout);
        outputPanelLayout.setHorizontalGroup(
            outputPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(outputPanelLayout.createSequentialGroup()
                .addGroup(outputPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(outputPanelLayout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(BMIText, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(65, 65, 65)
                        .addComponent(idealWeightText, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(65, 65, 65)
                        .addComponent(bodyFatText, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(outputPanelLayout.createSequentialGroup()
                        .addGap(201, 201, 201)
                        .addComponent(outputLabel)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(outputPanelLayout.createSequentialGroup()
                .addGap(35, 35, 35)
                .addComponent(outputLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(outputLabel2)
                .addGap(78, 78, 78)
                .addComponent(outputLabel3)
                .addGap(33, 33, 33))
        );
        outputPanelLayout.setVerticalGroup(
            outputPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(outputPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(outputPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(outputLabel1)
                    .addComponent(outputLabel2)
                    .addComponent(outputLabel3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(outputPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BMIText, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(idealWeightText, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(bodyFatText, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(outputLabel)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        dataStatusLabel.setForeground(new java.awt.Color(23, 155, 119));
        dataStatusLabel.setText("Fill above Fields and click button below");

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(37, 37, 37)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(8, 8, 8)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel2)
                                            .addComponent(jLabel5))
                                        .addGap(53, 53, 53)
                                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                            .addComponent(genderComboBox, 0, 145, Short.MAX_VALUE)
                                            .addComponent(ageText)
                                            .addComponent(heightText)
                                            .addComponent(weightText)))
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel6)
                                    .addComponent(dataStatusLabel))
                                .addGap(18, 18, 18)
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(heightUnitsComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(weightUnitsComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                    .addComponent(calculateBMIButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(outputPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(35, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(39, 39, 39)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel2)
                    .addComponent(genderComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(39, 39, 39)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel5)
                    .addComponent(ageText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(39, 39, 39)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(heightUnitsComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(heightText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(39, 39, 39)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(weightUnitsComboBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(weightText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(dataStatusLabel)
                .addGap(7, 7, 7)
                .addComponent(calculateBMIButton, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 22, Short.MAX_VALUE)
                .addComponent(outputPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(24, 24, 24))
        );

        jPanel3.setBackground(new java.awt.Color(23, 155, 119));

        jLabel1.setFont(new java.awt.Font("Gotham Bold", 0, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("BMI Calculator");

        jTextArea1.setColumns(20);
        jTextArea1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jTextArea1.setForeground(new java.awt.Color(23, 155, 119));
        jTextArea1.setRows(5);
        jTextArea1.setText("\nVery Severly Underweight \t  <16\nSeverly Underweight\t16 -17\nUnderweight\t\t17 - 18.5\nNormal\t\t18.5 - 25\nOver Weight\t\t25 - 30\nObese Class I\t\t30 - 35\nObese Class II\t\t35 - 40\nObese Class III\t\t  >40\n");
        jScrollPane1.setViewportView(jTextArea1);

        jLabel7.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel7.setForeground(new java.awt.Color(255, 255, 255));
        jLabel7.setText("BMI Classificaton Chart");

        jLabel8.setText("FATIMA MUBEEN");

        jLabel9.setText("2015-CS-111");

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                .addContainerGap(35, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addGap(35, 35, 35))
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel9)
                    .addComponent(jLabel8)
                    .addComponent(jLabel7)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jLabel1)
                .addGap(88, 88, 88)
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 182, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel8)
                .addGap(7, 7, 7)
                .addComponent(jLabel9)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, 0)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void heightUnitsComboBoxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_heightUnitsComboBoxActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_heightUnitsComboBoxActionPerformed

    private void calculateBMIButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_calculateBMIButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_calculateBMIButtonActionPerformed
    
    /**
     *  calculateBMIButton clicked event performed
     */
    private void calculateBMIButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_calculateBMIButtonMouseClicked
        // TODO add your handling code here:
        String BMI;
        String bodyFat;
        String idealWeight;
        if(setAge(ageText.getText())&&
                setHeightInMeters(heightText.getText(),""+heightUnitsComboBox.getSelectedItem())&&
                        setWeightInKg(weightText.getText(),""+weightUnitsComboBox.getSelectedItem())){
            dataStatusLabel.setText("Data Entered Successfully. ReEnter data and click below to Calculate BMI again");
            BMI=String.format("%.2f", getBMI());
            bodyFat=String.format("%.2f", getBodyFat(""+genderComboBox.getSelectedItem()));
            idealWeight=String.format("%.2f", getIdealWeight(""+genderComboBox.getSelectedItem()));
            outputPanel.show();
            BMIText.setText(BMI);
            idealWeightText.setText(idealWeight);
            bodyFatText.setText(bodyFat);
        }
        else{
            /* if setters in above if couldnt set all values user is prompted */
            dataStatusLabel.setText("Enter Correct Data and Try Again"); 
        }
    }//GEN-LAST:event_calculateBMIButtonMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(BMI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(BMI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(BMI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(BMI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new BMI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField BMIText;
    private javax.swing.JTextField ageText;
    private javax.swing.JTextField bodyFatText;
    private javax.swing.JButton calculateBMIButton;
    private javax.swing.JLabel dataStatusLabel;
    private javax.swing.JComboBox<String> genderComboBox;
    private javax.swing.JTextField heightText;
    private javax.swing.JComboBox<String> heightUnitsComboBox;
    private javax.swing.JTextField idealWeightText;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JLabel outputLabel;
    private javax.swing.JLabel outputLabel1;
    private javax.swing.JLabel outputLabel2;
    private javax.swing.JLabel outputLabel3;
    private javax.swing.JPanel outputPanel;
    private javax.swing.JTextField weightText;
    private javax.swing.JComboBox<String> weightUnitsComboBox;
    // End of variables declaration//GEN-END:variables
}
