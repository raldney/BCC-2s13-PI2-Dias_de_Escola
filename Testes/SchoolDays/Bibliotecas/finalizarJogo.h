int fecharJogo()
{
    al_destroy_display(Display);
    al_destroy_event_queue(eventosQueue);
    al_destroy_bitmap(fundoDisplay);

    return 0;
}
