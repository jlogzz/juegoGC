

#ifndef Tetris_proj_keyboard_h
#define Tetris_proj_keyboard_h





void keyboardListener(unsigned char key, int mouseX, int mouseY)
{
    if(estado == INICIO || estado == FINAL ) {
        switch (key)
        {
            case 'j':
                estado = JUEGO;
                init3d();
                break;
            case 'i':
                estado = CONTROLES;
                glutPostRedisplay();
                break;
        }
    } else if(estado == CONTROLES) {
        switch (key)
        {
            case 'j':
                estado = JUEGO;
                init3d();
                break;
            case 'v':
                estado = INICIO;
                glutTimerFunc(10, rotacionTextura, 0);
                glutPostRedisplay();
                break;
        }
    }else if(estado == JUEGO) {
        switch (key)
        {
            case 'w':
                //rotacion
                break;
            case 'a':
                if(vista == 1)
                {
                    rotacion-=.1;
                    
                    glutPostRedisplay();
                }
                break;
            case 'd':
                if(vista == 1)
                {
                    rotacion+=.1;
                    glutPostRedisplay();
                }
                break;
            case 's':
                BASS_Start();
                BASS_ChannelPlay(music, true);
                BASS_Pause();
                break;
            case 'p':
                BASS_Pause();
                break;
            case 'P':
                BASS_Start();
                break;
            case 'r':
                BASS_Start();
                BASS_ChannelPlay(music, true);
                break;
            case 'E':
                endProg();
                break;
            case ' ':
                while (mover(piezaActual, 0, -1, 0)) {}
                break;
            case 'y':
                rotateCCW(piezaActual);
                break;
            case 'u':
                rotateCW(piezaActual);
                break;
            case 'h':
                barrelCCW(piezaActual);
                break;
            case 'j':
                barrelCW(piezaActual);
                break;
            case '1':
                vista = 1;
                break;
            case '2':
                vista = 2;
                break;
            default:
                break;
        }
    }
}

void specialKeyboardListener(int key, int mouseX, int mouseY)
{
    switch (key) {
        case GLUT_KEY_DOWN:
            mover(piezaActual, 0, 0, 1);
            break;
        case GLUT_KEY_UP:
            mover(piezaActual, 0, 0, -1);
            break;
        case GLUT_KEY_LEFT:
            mover(piezaActual, -1, 0, 0);
            break;
        case GLUT_KEY_RIGHT:
            mover(piezaActual, 1, 0, 0);
            break;
        default:
            break;

    }
    /*
    BASS_ChannelSetAttribute(music, BASS_ATTRIB_VOL, volume);
     case GLUT_KEY_DOWN:
     if (volume >= 0.1)
     {
     volume -= 0.1;
     }
     break;
     case GLUT_KEY_UP:
     if (volume <= .9) {
     volume += 0.1;
     }*/
}

void KBinit()
{
    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyboardListener);
}


#endif
