#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int temperature = 0;
int pressure = 0;
bool stop_system = false;

/* Return a random value in [0, maximum] */
int aleatoire(int maximum) {
    return rand() % (maximum + 1);
}

void* controller(void* arg) {
    while (!stop_system) {
        pthread_mutex_lock(&mutex);
        // Attendre un signal (température ou pression mise à jour)
        pthread_cond_wait(&cond, &mutex);

        // Vérifier les seuils
        if (pressure >= 45) {
            printf("[controller]: pressure too high (%d) -> danger - shutdown system SOON\n", pressure);
            stop_system = true;
        } else {
            printf("[controller]: pressure modified (%d) but nothing dangerous\n", pressure);
        }

        if (temperature >= 60) {
            printf("[controller]: temperature too high (%d) -> danger - shutdown system SOON\n", temperature);
            stop_system = true;
        } else {
            printf("[controller]: temperature modified (%d) but nothing dangerous\n", temperature);
        }

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* t_sensor(void* arg) {
    sleep(1 + aleatoire(2));
    while (!stop_system) {
        pthread_mutex_lock(&mutex);
        temperature += 10 + aleatoire(2);
        printf("[t_sensor]: temperature is %d\n", temperature);
        pthread_cond_broadcast(&cond); // Notifier le contrôleur
        pthread_mutex_unlock(&mutex);
        usleep(200000 + aleatoire(2) * 100000); // Sleep 0.2s + aléatoire(2) * 0.1s
    }
    return NULL;
}

void* p_sensor(void* arg) {
    sleep(1 + aleatoire(2));
    while (!stop_system) {
        pthread_mutex_lock(&mutex);
        pressure += 10 + aleatoire(2);
        printf("[p_sensor]: pressure is %d\n", pressure);
        pthread_cond_broadcast(&cond); // Notifier le contrôleur
        pthread_mutex_unlock(&mutex);
        usleep(200000 + aleatoire(2) * 100000); // Sleep 0.2s + aléatoire(2) * 0.1s
    }
    return NULL;
}

int main(void) {
    srand(time(NULL)); // Initialiser le générateur aléatoire

    pthread_t thread_controller, thread_t_sensor, thread_p_sensor;

    pthread_create(&thread_controller, NULL, controller, NULL);
    pthread_create(&thread_t_sensor, NULL, t_sensor, NULL);
    pthread_create(&thread_p_sensor, NULL, p_sensor, NULL);

    // Attendre la fin des threads
    pthread_join(thread_controller, NULL);
    pthread_join(thread_t_sensor, NULL);
    pthread_join(thread_p_sensor, NULL);

    printf("Main thread: All stopped\n");
    return 0;
}
